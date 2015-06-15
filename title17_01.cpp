class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int k = pow(3, digits.length());
        if( k==1) k=0;
        vector<string> ret;
        for( int i=0; i<k; ++i)
        {
            char chs[100];
            int idx = i;
            for( int j=0; j<digits.length(); ++j)
            {
                int division = pow(3, digits.length()-1-j);
                int idx0 = idx/division;
                idx %= division;
                char first = 'a'+(digits[j]-'2')*3;
                chs[j] = first + idx0;
            }
            chs[digits.length()] = '\0';
            ret.push_back( string(chs));
        }
        return ret;
    }
};