class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return string("");
        char chs[10000];
        int idx = 0;
        while(1)
        {
            char ch;
            bool abort = 0;
            for( int i=0; i<strs.size(); ++i)
            {
                if( idx>=strs[i].length())
                {
                    abort = 1;
                    break;
                }
                if(i==0)
                {
                    ch = strs[i][idx];
                }
                else
                {
                    if(ch!=strs[i][idx])
                    {
                        abort = 1;
                        break;
                    }
                }
            }
            if(abort)
            {
                break;
            }
            chs[idx] = ch;
            idx++;
        }
        chs[idx]='\0';
        return string(chs);
    }
};