//////////////////////////////////////////////////////////////////////////
// 03 - Longest Substring Without Repeating Characters

//Given a string, find the length of the longest substring without repeating characters.
//For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
//For "bbbbb" the longest substring is "b", with the length of 1.

//#define TITLE03
#ifdef TITLE03

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int index = 0;
		unordered_map< char, int> umaps;
		int pre = 0;
		int maxLen = 0;
		while ( index<s.length())
		{
			if ( umaps.find( s[index]) != umaps.end())
			{
				if (index-1-pre+1 > maxLen)
				{
					maxLen = index- 1 - pre + 1;
				}
				for (int j = pre; j < umaps[s[index]]; ++j)
				{
					umaps.erase(s[j]);
				}
				pre = umaps[s[index]] + 1;
				
			}
			else
			{
				if (index - pre + 1 > maxLen)
				{
					maxLen = index - pre + 1;
				}
			}
			umaps[s[index]] = index;
			index++;
		}
	
		return maxLen;
	}
};

int main()
{
	Solution s;
	s.lengthOfLongestSubstring("aswe");
}

#endif