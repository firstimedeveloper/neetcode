/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		
		for (size_t i=0; i<nums.size()-1; ++i) {
			for (size_t j=i+1; j<nums.size(); ++j) {
				if (nums[i] + nums[j] == target) {
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
			}
		}
		return ret;
    }
};

int main() {
	Solution	sol;
	vector<int>	nums = {3, 2, 4};
	int			target = 6;

	vector<int> ans = sol.twoSum(nums, target);

	vector<int>::iterator it;
	cout << "[ ";
	for (it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << " ";
	}
	cout << "]\n";
}
