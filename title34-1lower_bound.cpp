class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        int idx1 = lower_bound( nums.begin(), nums.end(), target) - nums.begin();
        ret.push_back( nums[idx1]==target?idx1: -1);
        int idx2 = lower_bound( nums.rbegin(), nums.rend(), target, greater<int>()) - nums.rbegin();
        idx2 = nums.size()-1-idx2;
        ret.push_back( nums[idx2]==target?idx2: -1);
        return ret;
    }
};