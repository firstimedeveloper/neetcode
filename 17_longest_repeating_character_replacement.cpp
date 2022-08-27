/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int alpha[26] = {0};

	int findMax() {
		int max = 0;
		for (int i=0; i<26; ++i) {
			if (alpha[i] > max)
				max = alpha[i];
		}
		return max;
	}

	int characterReplacement(string s, int k) {
		int ret = 0;
		int l = 0;
		int r;
		for (r=0; r<(int)s.size(); ++r) {
			alpha[s[r] - 'A']++;
			while (r - l + 1 - findMax() > k) {
			cout << l << " " << r << " ";
			cout << s.substr(l, r - l + 1) << " " << findMax() << " " << ret << endl;
				alpha[s[l++] - 'A']--;
			}
			ret = max(ret, r - l + 1);
		}
		return ret;
	}
};

int main() {
	string s = "AABABBA";
	Solution sol;


	cout << sol.characterReplacement(s, 1);

}
