/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
*/

#include <bits/stdcpp.h>
using namespace std;

class Solution {
public:
	bool isOpen(char c) {
		if (c == '(' || c == '[' || c == '{')
			return true;
		return false;
	}

	bool isMatch(char a, char b) {
		if (a == '(')
			if (b == ')') return true;
			else return false;
		else if (a == '[')
			if (b == ']') return true;
			else return false;
		else
			if (b == '}') return true;
			else return false;
		return false;
	}

	bool isValid(string s) {
		stack<int> st;
		int temp;

		for (auto &c: s) {
			if (isOpen(c)) {
				st.push(c);
			} else {
                if (st.empty()) return false;
				if (!isMatch(st.top(), c))
					return false;
				st.pop();
			}
		}	
        return st.empty();
	}
};
