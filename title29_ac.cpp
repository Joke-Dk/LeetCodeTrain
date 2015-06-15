class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0) return INT_MAX;
        if(divisor==INT_MIN) return dividend==INT_MIN?1:0;
        if(dividend==0) return 0;
        bool sign = 1;
        
        if( dividend>0 && divisor<0) sign = 0;
        if( dividend<0 && divisor>0) sign = 0;
        unsigned int dividend0 = abs(dividend);
        if( dividend==INT_MIN) dividend0 = (unsigned int)INT_MAX + 1;
        unsigned int  divisor0 = abs(divisor);
        unsigned int ret = 0;
        unsigned int val;
        unsigned int sum = 0;
        while( dividend0>=sum)
        {
            unsigned int cut = divisor0;
            val = 1;
            while( cut<<1 >0 && cut<<1 < dividend0-sum)
            {
                cut <<= 1;
                val <<= 1;
            }
            sum += cut;
            ret += val;
        }
        ret -= val;
        if(ret>(unsigned int)INT_MAX && sign) return INT_MAX;
        return sign? ret:-ret;
        
    }
};