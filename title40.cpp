class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> uset;
        for( int i=0; i<nums.size(); ++i)
        {
            uset.insert(nums[i]);
        }
        int idx = 1;
        while( uset.find(idx)!=uset.end()) idx++;
        return idx;
    }
};