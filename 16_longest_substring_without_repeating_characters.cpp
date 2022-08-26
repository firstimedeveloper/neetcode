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
		unordered_set<int> alpha;
		size_t ret = 0;
		size_t l = 0;
		size_t r = 0;
		while (r < s.size()) {
			if (alpha.count(s[r])) {
				while (s[l] != s[r])
						alpha.erase(s[l++]);
				alpha.erase(s[l++]);
			} else {
				alpha.insert(s[r++]);
				ret = max(ret, r - l);

			}
		}
		return max(ret, r - l);
	}
};

int main() {
	string s = "bbbbbb";
	Solution sol;


	cout << sol.lengthOfLongestSubstring(s);

}
