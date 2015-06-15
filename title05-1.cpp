//////////////////////////////////////////////////////////////////////////
// 05 - Longest Palindromic Substring 

//Given a string S, find the longest palindromic substring in S.You may assume that the maximum length of S is 1000, 
//and there exists one unique longest palindromic substring.

//#define TITLE
#ifdef TITLE

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		const int MAX = 1001;
		bool dp[MAX][MAX];
		memset(dp, 0, sizeof(dp));
		
		int leng = s.length();
		//fresh dp-map
		for (int l = 1; l <= s.length(); ++l)
		{
			for (int j = 0; j <= s.length()-l; ++j)
			{
				if (l==1)
				{
					dp[j][j + l - 1] = 1;
				}
				else if (l==2)
				{
					dp[j][j + l - 1] = (s[j] == s[j + 1] ? 1 : 0);
				}
				else
				{
					dp[j][j + l - 1] = ( (s[j] == s[j + l - 1] && dp[j + 1][j + l - 1 - 1]) ? 1 : 0);
				}
			}
		}

		//find the max-one
		int len = 1, j = 0;
		bool found = 0;
		for (len = s.length(); len > 0; --len)
		{
			for (j = 0; j <= s.length() - len; ++j)
			{
				if ( dp[j][j+len-1])
				{
					found = 1;
					break;
				}
			}
			if (found)
			{
				break;
			}
		}


		return s.substr( j, len);
	}
};
int main()
{
	Solution s;
	cout << s.longestPalindrome(string("ccd")) << endl;;

	return 0;
}

#endif