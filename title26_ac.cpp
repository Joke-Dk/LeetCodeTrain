class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre = 0;
        for(int i=0; i<nums.size(); ++i)
        {
            if(i==0)
            {
                pre = nums[0];
            }
            else
            {
                if(nums[i]==pre)
                {
                    nums.erase( nums.begin()+i);
                    i--;
                }
                else
                {
                    pre = nums[i];
                }
            }
        }
        return nums.size();
    }
};