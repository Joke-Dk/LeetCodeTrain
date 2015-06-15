//////////////////////////////////////////////////////////////////////////
// 04 - Median of Two Sorted Arrays

//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).

//#define TITLE
#ifdef TITLE

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if ( nums2.size()>nums1.size())
		{
			swap(nums1, nums2);
		}
		
		const int INF = 0x7FFFFFFF;
		int midLen = (nums1.size() + nums2.size() + 1) / 2;
		int step = (nums1.size()+1)/2;
		int index1 = step-1;
		int index2 = midLen - index1 - 2;
		int later1, later2, now1, now2;
		while (index1>=-1 && index2>=-1)
		{
			step = (step + 1) / 2;
			//judge
			now1 = index1 > -1 ? nums1[index1] : -INF;
			now2 = index2 > -1 ? nums2[index2] : -INF;
			later1 = (index1+1 < nums1.size()) ? nums1[index1+1] : INF;
			later2 = (index2+1 < nums2.size()) ? nums2[index2+1] : INF;
			if (now1>later2)// too big
			{
				index1 -= step;
				index1 = max(index1, midLen - int(nums2.size()) - 1);
			}
			else if (now2 > later1)//assert( len2>0) // too small
			{
				index1 += step;
				index1 = min(index1, midLen - 1);
			}
			else
			{
				break;
			}
			index2 = midLen - index1 - 2;
		}
		double ans = max(now1, now2);

		if ( (nums1.size()+nums2.size())%2==0)
		{
			//find the two median of the array
			double ans2 = min(later1, later2);
			ans = (ans + ans2) / 2.f;
		}
		return ans;
	}
};

int main()
{
	int n1[] = {  1, 2, 3, 4 ,6, 7};
	int n2[] = { 5, 6, 7, 8, 9};
	vector<int> v1(n1, n1 + 6);
	vector<int> v2(n2, n2 + 1);
	Solution s;
	double ret = s.findMedianSortedArrays(v1, v2);

	return 0;
}
#endif