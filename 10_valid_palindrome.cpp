/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
	static bool nonAlpha(char c) {
		return !isalnum(c);
	}

	void stripNonAlpha(string &s) {
		s.erase(remove_if(s.begin(), s.end(), nonAlpha), s.end());
	}
	bool isPalindrome(string s) {

		// cout << s << endl;
		stripNonAlpha(s);
		// cout << s << endl;
		int i = 0, j = s.size()-1;
		while (i < j) {
			if (tolower(s[i++]) != tolower(s[j--]))
				return false;
		}
		return true;
	}
};

int main() {
	
	// jstring s = "A man, a plan, a canal: Panama";
	string s = "0P";

	Solution sol;

	cout << sol.isPalindrome(s);
}
