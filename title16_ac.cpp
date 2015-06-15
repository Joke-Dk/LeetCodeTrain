class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort( nums.begin(), nums.end());
        int maxDiff = INT_MAX/2;
        int ret = 0;
        for( int i=0; i<nums.size(); ++i)
        {
            int a = nums[i];
            int idx1 = i+1, idx2 = nums.size()-1;
            while( idx1< idx2)
            {
                int diff = a+nums[idx1]+nums[idx2] - target;
                if( abs(diff)<maxDiff)
                {
                    maxDiff = abs(diff);
                    ret = a+nums[idx1]+nums[idx2];
                }
                if(diff<0)
                {
                    idx1++;
                }
                else if(diff>0)
                {
                    idx2--;
                }
                else
                {
                    return target;
                }
            }
        }
        return ret;
    }
};