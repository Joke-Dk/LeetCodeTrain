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
        /*if(uset.find( target)!=uset.end())
        {
            vec.push_back(target);
            ret.push_back(vec);
            vec.pop_back();
        }*/
        if(idx>=candidates.size()) return;
        int val = candidates[idx];
        uset.erase(val);
        for( int i=0; i<=target/val; ++i)
        {
            vector<int> arr(i, val);
            vec.insert(vec.end(), arr.begin(), arr.end());
            recusive(idx+1, target-i*val, candidates);
            vec.erase(vec.end()-i, vec.end());
        }
        uset.insert(val);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort( candidates.begin(), candidates.end());
        for( int i=0; i<candidates.size(); ++i)
        {
            uset.insert(candidates[i]);
        }
        recusive(0, target, candidates);
        return ret;
    }
    vector<vector<int>> ret;
    vector<int> vec;
    unordered_set<int> uset;
};