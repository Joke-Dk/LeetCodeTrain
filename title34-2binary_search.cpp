class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx[2]={INT_MAX, -1};
        for( int id=0; id<2; ++id)
        {
            int low = 0, high = nums.size()-1;
            while( low<=high)
            {
                int mid = (low+high)/2;
                if( nums[mid]==target)
                {
                    if(id==0)
                    {
                        idx[id] = min(idx[id], mid);
                        high = mid-1;
                    }
                    else
                    {
                        idx[id] = max(idx[id], mid);
                        low = mid+1;
                    }
                }
                else if( nums[mid]<target)
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
            idx[0] = (idx[0]==INT_MAX? -1:idx[0]);
        }
        return vector<int>(idx, idx+2);
    }
};