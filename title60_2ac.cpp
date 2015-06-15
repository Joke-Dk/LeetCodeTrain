class Solution {
public:
    
    string getPermutation(int n, int k) {
        vector<int> vec;
        for(int i=0; i<n; ++i)
            vec.push_back(i+1);
        int sum = 1;
        for(int i=1; i<=n; ++i) sum*=i;
        
        string ret;
        k--;
        for(int i=0; i<n; ++i)
        {
            sum /= n-i;
            int idx = k/sum;
            ret.push_back('0'+vec[idx]);
            vec.erase(vec.begin()+idx);
            k-=sum*idx;
        }
        return ret;
    }
    
};