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
	
	double findKth( const vector<int>& nums1 , const vector<int>& nums2, int k) // recusive
	{
		//assert nums1 < nums2
		if (nums1.size()>nums2.size())
		{
			return findKth(nums2, nums1, k);
		}
		if (nums1.size()==0)
		{
			return nums2[k-1];
		}
		if (k==1)
		{
			return min(nums1[0], nums2[0]);
		}
		int n1 = min(k / 2, int(nums1.size()));
		int n2 = k - n1;
		if ( nums1[n1-1] > nums2[n2-1])
		{
			vector<int> new2(nums2.begin()+n2, nums2.end());
			return findKth(nums1, new2, k - n2);
		}
		else if (nums1[n1-1] < nums2[n2-1])
		{
			vector< int> new1(nums1.begin() + n1, nums1.end());
			return findKth(new1, nums2, k - n1);
		}
		else
		{
			return nums1[n1-1];
		}
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int total = nums1.size() + nums2.size();
		if (total%2!=0)
		{
			return findKth(nums1, nums2, total / 2 + 1);
		}

		return (findKth(nums1, nums2, total / 2) + findKth(nums1, nums2, total / 2 + 1)) / 2.0;
		
	}
};

int main()
{
	int n1[] = {  1, 2, 3, 4 ,6, 7};
	int n2[] = { 1, 6, 7, 8, 9};
	vector<int> v1(n1, n1 + 1);
	vector<int> v2(n2, n2 + 1);
	Solution s;
	double ret = s.findMedianSortedArrays(v1, v2);
	cout << ret << endl;
	return 0;
}
#endif