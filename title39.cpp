class Solution {
public:
    void backtracking( int idx, int target)
    {
        if(target==0)
        {
            ret.push_back(vec);
            return;
        }
        else if(target<0)
        {
            return;
        }
        
        for(int i=idx; i<data.size(); ++i)
        {
            if(i==idx || data[i]!=data[i-1])
            {
                int val = data[i];
                vec.push_back(val);
                backtracking( i+1, target-val);
                vec.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort( candidates.begin(), candidates.end());
        data = candidates;
        backtracking(0, target);
        return ret;
    }
    
    vector<int> data;
    vector<int> vec;
    vector< vector<int>> ret;
};