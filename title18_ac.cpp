class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ret;
		sort(nums.begin(), nums.end());
		for (int i = 0; i<nums.size(); ++i)
		{
			if (i>0 && nums[i - 1] == nums[i]) continue;
			int a = nums[i];
			for (int j = i + 1; j<nums.size(); ++j)
			{
				if (j>i + 1 && nums[j - 1] == nums[j]) continue;
				int b = nums[j];
				int idx1 = j + 1, idx2 = nums.size() - 1;
				while (idx1 < idx2)
				{
					int sums = a + b + nums[idx1] + nums[idx2];
					if (sums<target)
					{
						idx1++;
					}
					else if (sums>target)
					{
						idx2--;
					}
					else
					{
						int c = nums[idx1];
						ret.push_back(vector<int>({ a, b, nums[idx1], nums[idx2] }));
						while (idx1<nums.size()&&  nums[idx1] == c)
						{
							idx1++;
						}
						idx2--;
					}
				}
			}
		}
		return ret;
	}
};