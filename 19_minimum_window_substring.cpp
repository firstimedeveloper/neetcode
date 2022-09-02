/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

algo:
init window, target (set)
init variables have, need (int) to keep count of matches.
window pos(l, r) = (-1, -1) ""
	increment r until have == need
	record pos
	increment l until have != need
repeat until r == s.size()
return pos
*/ 

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void print_alpha(int *s) {
	
		for (int i=0; i<58; ++i) {
			if (s[i])
				cout << (char)('A' + i) << s[i] << " ";
		}
		cout << endl;
	}
	string minWindow(string s, string t) {
		int idx;
		int ret_l = 0;
		int ret_len = 0;
		int l = 0;
		int r = 0;
		int have = 0;
		int need = 0;
		int a_s[58] = {0};
		int a_t[58] = {0};
		for (auto c: t) {
			idx = c - 'A';
			a_t[idx]++;
			need++;
		}
		/*
		while (r < (int)t.size() && have != need) {
			if (have == need) break ;
			idx = s[r] - 'A';
			if (a_s[idx] && a_s[idx] < a_t[idx])
				have++;
			a_s[idx]++;
			r++;	
		} 
		*/

		for (; l<(int)s.size();) {
			print_alpha(a_t);
			print_alpha(a_s);
			cout << "need: " << need << " have: " << have << endl;

			if (have == need) {
				idx = s[l] - 'A';
				ret_l = l;
				ret_len = r - l;

				cout << s.substr(ret_l, ret_len) << endl;
				if (a_t[idx] && a_s[idx] >= a_t[idx])
					have--;
				a_s[idx]--;
				l++;
			} else {
				idx = s[r] - 'A';
				if (a_s[idx] < a_t[idx] && a_s[idx] + 1 <= a_t[idx])
					have++;
				a_s[idx]++;
				r++;
			}
			
		}
		return s.substr(ret_l, ret_len);
	}
};

int main() {
	string s = "ADOBECODEBANC", t = "ABC";

	Solution sol;
	string ret = sol.minWindow(s, t);
	cout << "answ: " << ret << endl;
}
