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

//#define TITLE
#ifdef TITLE

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int idx1 = 0;
		int idx2 = 0;
		while (idx1<s.length() && idx2<p.length())
		{
			//assert p[idx]!='*'
			bool hasMany = 0;
			if ( idx2+1<p.length() && p[idx2+1]=='*')
			{
				hasMany = 1;
			}

			if (p[idx2] == '.' || (s[idx1] == p[idx2]))
			{
				if (hasMany)
				{
					idx1++;;
					while (idx1<s.length() && s[idx1-1]==s[idx1])
					{
						idx1++;
					}
				}
				else
				{
					idx1++;
				}
			}
			
			if (hasMany)
			{
				idx2 += 2;
			}
			else
			{
				idx2++;
			}
		}

		return idx1 == s.length();
	}
};
int main()
{
	Solution s;
	cout << s.isMatch( "aabbb", "c*a*b*") << endl;;

	return 0;
}

#endif