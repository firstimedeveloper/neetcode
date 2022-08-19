/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void	print(vector<vector<string>> vec) {
		for (auto &i: vec) {
			printf("[ ");
			for (auto &j: i) {
				cout << j << ' ';
			}
			printf("] ");
		}
		printf("\n");
	}

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ret;
		vector<string> anagrams;
		vector<string>::iterator it;
		string	next;
		string	prev;

		prev = strs.front();
		ret.push_back(vector<string>{prev});
		sort(prev.begin(), prev.end());
		anagrams.push_back(prev);

		for (it = ++strs.begin(); it != strs.end(); ++it) {
			int found = false;
			next = *it;
			sort(next.begin(), next.end());
			for (size_t i=0; i<anagrams.size(); ++i) {
				if (anagrams[i] == next) {
					ret[i].push_back(*it);
					found = true;
				}
			}
			if (!found) {
				ret.push_back(vector<string>{*it});
				anagrams.push_back(next);
			}
		}
        return ret;
    }
};

int main() {

	Solution sol;
	
	vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

	sol.print(sol.groupAnagrams(strs));
}
