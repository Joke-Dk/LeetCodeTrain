//////////////////////////////////////////////////////////////////////////
// 06 - ZigZag Conversion 

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
	string convert(string s, int numRows) {
		if (numRows==1)
		{
			return s;
		}
		string ret;
		int len = s.length();
		int unit = 2 * numRows - 2;
		for (int k = 0; k < numRows; ++k)
		{
			for (int i = 0; i <= len / numRows + 1; ++i)
			{
				int idx1 = i*unit + k;
				if (idx1<len&& k != numRows - 1)
				{
					ret.push_back(s[idx1]);
				}
				
				int idx2 = (i + 1)*unit - k;
				if (idx2 < len&&k != 0)
				{
					ret.push_back(s[idx2]);
				}
			}
		}
		return ret;
		
	}
};

int main()
{
	Solution s;
	cout << s.convert(string("A"), 1) << endl;;

	return 0;
}

#endif