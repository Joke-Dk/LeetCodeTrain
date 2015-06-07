class Solution {
public:
	stack<int> stk;
	vector<string> ret;
	vector<char> chs;
	int count;
	int N;
	void recusive(int idx, bool add)
	{
		if (add)
		{
			count++;
			chs.push_back('(');
			stk.push(1);
		}
		else
		{
			chs.push_back(')');
			stk.pop();
		}

		if (idx >= 2 * N - 1)
		{
			string str(chs.begin(), chs.end());
			ret.push_back(str);
			//return;
		}

		if (!stk.empty())// - pop
		{
			recusive(idx + 1, 0);
		}
		if (count<N)
		{
			recusive(idx + 1, 1);
		}

		//clear
		if (add)
		{
			count--;
			stk.pop();
		}
		else
		{
			stk.push(1);
		}
		chs.pop_back();
	}
	vector<string> generateParenthesis(int n) {
		count = 0;
		N = n;
		recusive(0, 1);
		return ret;
	}
};