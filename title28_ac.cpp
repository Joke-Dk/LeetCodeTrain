class Solution {
public:
    int strStr(string haystack, string needle) {
        if( needle.length()==0) return 0;
        int idx=0;
        while( idx<haystack.length())
        {
            if(needle==haystack.substr(idx, needle.length()))
            {
                return idx;
            }
            idx++;
        }
        return -1;
    }
};