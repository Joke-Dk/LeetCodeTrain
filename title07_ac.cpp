class Solution {
public:
    int reverse(int x) {
        if (x==0) return 0;
        bool negative = x>0?0:1;
        x = abs(x);
        vector<int> vec;
        while( x!=0)
        {
            vec.push_back( x%10);
            x/=10;
        }
        
        //output
        int ret = 0;
        for( int i=0; i<vec.size(); ++i)
        {
            if(ret>(INT_MAX-vec[i])/10) return 0;
            ret*=10;
            ret+=vec[i];
        }
        ret*=(negative?-1:1);
        return ret;
    }
};