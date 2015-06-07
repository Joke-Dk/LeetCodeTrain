#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& vec, int target)
{
	int low = 0, high = vec.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (vec[mid] == target)
		{
			return mid;
		}
		else if (vec[mid]<target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}
int main()
{
	vector<int> vec({1, 3, 4, 5, 12});
	int ret = binarySearch(vec, 5);
	cout << ret << endl;
	return 0;
}