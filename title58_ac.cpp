class Solution {
public:
    int lengthOfLastWord(string s) {
        int pre = -1;
        for( int i=s.length()-1; i>=0; --i)
        {
            if(pre<0&&s[i]!=' ') pre = i;
            else if(pre>=0 && s[i]==' ')
            {
                return pre-i;
            }
        }
        if(pre>=0) return pre+1;
        return 0;
    }
};