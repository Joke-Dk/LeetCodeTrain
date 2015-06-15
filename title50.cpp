class Solution {
public:
    double myPow(double x, int n) {
        bool negative = n<0?1:0;
        n=abs(n);
        double ret = 1.f;
        while(n>0)
        {
            if(n&1)
            {
                ret*=x;
            }
            x*=x;
            n>>=1;
        }
        return negative? 1./ret: ret;
    }
};