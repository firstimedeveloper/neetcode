/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
*/

class Solution {
public:
	int is_op(string s) {
		if (s == "+" || s == "-" || s == "*" || s == "/")
			return true;
		return false;
	}

    int evalRPN(vector<string>& tokens) {
		stack<int> s;
		int temp;

		for (auto i=tokens.begin(); i!=tokens.end(); ++i) {
			if (is_op(*i)) {
				int a = s.top(); s.pop();
				int b = s.top(); s.pop();
				if (*i == "+")
					temp = b + a;
				else if (*i == "-")
					temp = b - a;
				else if (*i == "*")
					temp = b * a;
				else 
					temp = b / a;
				s.push(temp);
			} else {
				temp = stoi(*i);
				s.push(temp);
			}
		}
        
		return s.top();
    }
};
