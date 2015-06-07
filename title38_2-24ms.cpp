class Solution {
public:
    void recusive(int idx, int target, vector<int>& candidates)
    {
        if(target==0)
        {
            ret.push_back(vec);
            return;
        }
        if(target<0) return;
        for( int i=idx; i<candidates.size(); ++i)
        {
            int val = candidates[i];
            vec.push_back(val);
            recusive(i, target-val, candidates);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort( candidates.begin(), candidates.end());
        recusive(0, target, candidates);
        return ret;
    }
    vector<vector<int>> ret;
    vector<int> vec;
};