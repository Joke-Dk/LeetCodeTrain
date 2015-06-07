class Solution {
public:
	int longestValidParentheses(string s) {
		if (s == "") return 0;
		stack< int> stk;
		stk.push(-1);
		int idx = 0;
		int maxlen = 0;

		while (!stk.empty() && idx<s.length())
		{
		    int pre = stk.top();
		    if( pre!=-1 && s[pre]=='(' && s[idx]==')')
		    {
		        stk.pop();
		        maxlen = max( maxlen, idx-stk.top());
		    }
		    else
		    {
		        stk.push( idx);
		    }
			idx++;
		}
		return maxlen;
	}
};