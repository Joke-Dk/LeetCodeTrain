class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector< string> ret;
        if( digits.length()==0) return ret;
        ret.push_back("");
        string letters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for( int i=0; i<digits.length(); ++i)
        {
            int dig = digits[i]-'0';
            vector< string> tmp;
            for( int k=0; k<letters[dig].length(); ++k)
            {
                for( int j=0; j<ret.size(); ++j)
                {
                    tmp.push_back( ret[j]+letters[dig][k]);
                }
            }
            ret = tmp;
        }
        return ret;
    }
};