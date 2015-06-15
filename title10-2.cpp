//////////////////////////////////////////////////////////////////////////
// 10 - Regular Expression Matching 

//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line : "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows :
//
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

#define TITLE
#ifdef TITLE

#include <iostream>
#include <string>
using namespace std;

const int MAX = 1000;
bool dp[MAX][MAX];
bool visited[MAX][MAX];
class Solution {
public:

	string S;
	string P;
	bool getDp( int idx1, int idx2)
	{
		if (visited[ idx1][ idx2])
		{
			return dp[idx1][idx2];
		}
		if (idx1<0 && idx2<0)
		{
			return 1;
		}
		else if (idx1<0 && idx2>=0)
		{
			if (P[idx2]=='*')
			{
				return getDp(idx1, idx2 - 2);
			}
			return 0;
		}
		else if (idx1>=0 && idx2 < 0)
		{
			return 0;
		}

		bool hasMany = (P[idx2] == '*');
		int pre2 = hasMany ? idx2 - 1 : idx2;
		if (hasMany)
		{
			// * = 1
			bool dp01 = getDp(idx1 - 1, idx2);
			if (dp01 && (P[pre2]=='.' || S[idx1]==P[pre2]) )
			{
				visited[idx1][idx2] = 1;
				dp[idx1][idx2] = 1;
				return 1;
			}
			// * = 0
			bool dp10 = getDp(idx1, pre2-1);
			if (dp10)
			{
				visited[idx1][idx2] = 1;
				dp[idx1][idx2] = 1;
				return 1;
			}
		}
		else// no *
		{
			bool dp00 = getDp(idx1 - 1, pre2 - 1);
			if (dp00 && (P[pre2] == '.' || S[idx1] == P[pre2]))
			{
				visited[idx1][idx2] = 1;
				dp[idx1][idx2] = 1;
				return 1;
			}
		}
		visited[idx1][idx2] = 1;
		dp[idx1][idx2] = 0;
		return 0;
		
	}

	bool isMatch(string s, string p) {
		S = s;
		P = p;
		memset(dp, 0, sizeof(dp));
		memset(visited, 0, sizeof(visited));
		return getDp(s.length() - 1, p.length() - 1);
	}
};
int main()
{
	Solution s;
	cout << s.isMatch( "a", "ab*a") << endl;;

	return 0;
}

#endif