/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
        vector<int> alpha(255, 0);
		size_t ret = 0;
		size_t l = 0;
		size_t r = 0;
		while (r < s.size()) {
			while (alpha[s[r]])
				alpha[s[l++]]--;
			ret = max(ret, r - l + 1);
            alpha[s[r++]]++;

		}
		return ret;
	}
};

int main() {
	string s = "bbbbbb";
	Solution sol;


	cout << sol.lengthOfLongestSubstring(s);

}
