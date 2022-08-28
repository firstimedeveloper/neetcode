/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int a1[26] = {0};
	int a2[26] = {0};

	bool checkAlpha() {
		for (int i=0; i<26; ++i)
			if (a1[i] != a2[i])
				return false;
		return true;
	}

	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size()) return false;
		int l = 0;
		int r = 0;
		int matches = 0;
		int idx;
		// initialize our alpha array
		for (int i=0; i<(int)s1.size(); ++i) {
			a1[s1[i] - 'a']++;
			a2[s2[i] - 'a']++;
		}

		for (int i=0; i<26; ++i) {
			if (a1[i] == a2[i])
				matches++;
		}
		
		for (r = (int)s1.size(); r<(int)s2.size(); ++r) {
			cout << l << " " << r;
			cout << " ";
			cout << s2.substr(l, r-l+1);
			cout << " ";
			cout << matches << endl;
			if (matches == 26)
				return true;
			idx = s2[r] - 'a';
			a2[idx]++;
			if (a1[idx] == a2[idx])
				matches++;
			else if (a1[idx] + 1 == a2[idx])
				matches--;

			idx = s2[l] - 'a';
			a2[idx]--;
			if (a1[idx] == a2[idx])
				matches++;
			else if (a1[idx] - 1 == a2[idx])
				matches--;

			l++;
		}
		return matches == 26;
	}
};

int main() {
	string s1 = "ab";
	string s2 = "eidbaooo";
	Solution sol;
	cout << sol.checkInclusion(s1, s2);
}
