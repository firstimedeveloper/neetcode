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
		unordered_map<string, vector<string>> anagrams;

		for (size_t i=0; i<strs.size(); ++i) {
			string sorted = strs[i];
			sort(sorted.begin(), sorted.end());
			anagrams[sorted].push_back(strs[i]);
		}
		for (auto &anagram: anagrams) {
			ret.push_back(anagram.second);
		}
		return ret;
    }
};

int main() {

	Solution sol;
	
	vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

	sol.print(sol.groupAnagrams(strs));
}
