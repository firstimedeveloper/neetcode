class Solution {
public:

	// if open == n and close == n return add current string to the return vector.
	// if open is less than n, add ( to string and increment open.
	// if close is less than n, add ) to string and increment close.
	void recur(string s, int n, int open, int close, vector<string> &ret) {
		if (open == n && close == n) {
			ret.push_back(s);
			return ;
		}
		if (open < n)
			recur(s+"(", n, open+1, close, ret);
		if (close < open)
			recur(s+")", n, open, close+1, ret);
	}

    vector<string> generateParenthesis(int n) {
		vector<string> ret;

		recur("", n, 0, 0, ret);
        
		return ret;
    }
};
