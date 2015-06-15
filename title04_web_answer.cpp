//////////////////////////////////////////////////////////////////////////
// 04 - Median of Two Sorted Arrays
// web address http://blog.csdn.net/yutianzuijin/article/details/11499917/
//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).

//#define TITLE
#ifdef TITLE

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findKth(int a[], int m, int b[], int n, int k)
{
	//always assume that m is equal or smaller than n
	if (m > n)
		return findKth(b, n, a, m, k);
	if (m == 0)
		return b[k - 1];
	if (k == 1)
		return min(a[0], b[0]);
	//divide k into two parts
	int pa = min(k / 2, m), pb = k - pa;
	if (a[pa - 1] < b[pb - 1])
		return findKth(a + pa, m - pa, b, n, k - pa);
	else if (a[pa - 1] > b[pb - 1])
		return findKth(a, m, b + pb, n - pb, k - pb);
	else
		return a[pa - 1];
}

class Solution
{
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		int total = m + n;
		if (total & 0x1)
			return findKth(A, m, B, n, total / 2 + 1);
		else
			return (findKth(A, m, B, n, total / 2)
			+ findKth(A, m, B, n, total / 2 + 1)) / 2;
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