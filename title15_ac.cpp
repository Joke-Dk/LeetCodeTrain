class Solution {
public:

	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> vvec;
		unordered_map< int, int> umap;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (umap.find(nums[i]) == umap.end())
			{
				umap[nums[i]] = 0;
			}
			umap[nums[i]]++;
		}

		map< int, int> sortmap(umap.begin(), umap.end());
		for (map<int, int>::iterator it = sortmap.begin(); it != sortmap.end(); ++it)
		{
			int a = it->first;
			for (map<int, int>::iterator it2 = it; it2 != sortmap.end(); ++it2)
			{
				if (it == it2&&it->second == 1) continue;
				int addnum = (it == it2 ? 2 : 1);
				//find
				int b = it2->first;
				int c = -a - b;
				if ((c == b && umap.find(c) != umap.end() && it2->second > addnum)
					|| (c > b && umap.find(c) != umap.end())
					)
				{
					vector<int> tmp({ a, b, c });
					vvec.push_back(tmp);
				}
			}
		}
		return vvec;
	}
};