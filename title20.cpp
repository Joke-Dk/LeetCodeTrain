class Solution {
public:
    bool isMatch(char a, char b)
    {
        if(a=='(' && b==')')
            return 1;
        if(a=='[' && b==']')
            return 1;
        if(a=='{' && b=='}')
            return 1;
        return 0;
    }
    bool isValid(string s) {
        stack< char> stk;
        stk.push(' ');
        for( int i=0; i<s.length(); ++i)
        {
            if( isMatch( stk.top(), s[i]))
            {
                stk.pop();
            }
            else
            {
                stk.push( s[i]);
            }
        }
        return stk.top()==' ';
    }
};