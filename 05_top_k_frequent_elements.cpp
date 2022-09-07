/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
*/

#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}
class Solution {
public:
	void print(vector<int> nums) {
		printf("[");
		for (auto &i: nums) {
			printf(" %d ", i);
		}
		printf("]\n");
	}
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> freq;
		vector<int> ret;
		
		for (auto i = nums.begin(); i != nums.end(); ++i) {
			freq[*i]++;
		}

		vector<pair<int, int>> inv_freq(freq.begin(), freq.end());
		sort(inv_freq.begin(), inv_freq.end(), cmp);

		int j = 0;
		auto i = inv_freq.begin();
		while (j < k && i != inv_freq.end()) {
			ret.push_back(i->first);
			i++;
			j++;
		}


        return ret;
    }
};

int main() {
	vector<int> nums = {1,1,1,2,2,3,5,5,5,5,5,5};
	//vector<int> nums = {1, 2};

	Solution sol;

	sol.print(sol.topKFrequent(nums, 2)); // should be [1, 2]
}
