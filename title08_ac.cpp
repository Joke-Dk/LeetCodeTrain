class Solution {
public:
    int myAtoi(string str) {
        int ret = 0;
        bool negative = 0;
        bool positive = 0;
        bool hasdigit = 0;
        bool hassymbol = 0;
        for( int i=0; i<str.size(); ++i)
        {
            if( str[i]=='-' || str[i]=='+') {
                hasdigit = 1;
                if(hassymbol)
                {
                    return 0;
                }
                hassymbol = 1;
                if (str[i]=='-') negative = 1;
                continue;
            } 
            
            if( str[i]==' ') 
            {
                if(hasdigit)
                    break;
                else
                    continue;
            }
            if( str[i]>'9' || str[i]<'0') break;
            hasdigit = 1;
            int digit = str[i]-'0';
            if( ret>(INT_MAX-digit)/10 )
            {
                if( negative)
                    return INT_MIN;
                return INT_MAX;
                
            }
            ret *= 10;
            ret += digit;
        }
        ret *= (negative?-1:1);
        return ret;
    }
};