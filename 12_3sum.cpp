/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
[ -4 -1 -1 0 1 2]
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
	
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		vector<vector<int>> ret;
		for (size_t i=0; i<nums.size()-2; ++i) {
			if (i > 0 && nums[i] == nums[i-1]) continue;
			int l = i + 1;
			int r = nums.size() - 1;
			while (l < r) {
				int sum = nums[i] + nums[l] + nums[r];
				if (sum < 0)
					l++;
				else if (sum > 0)
					r--;
				else {
					ret.push_back({nums[i], nums[l], nums[r]});
					l++;
					while (nums[l] == nums[l-1] && l < r) l++;
				}
			}
		}
		return ret;
	}
};

void print(vector<vector<int>> vec) {
	cout << "[ ";
	for (auto i: vec) {
		cout << "[ ";
		for (auto j: i) {
			cout << j << " ";
		}
		cout << "] ";
	}
	cout << "]\n";

}

int main() {
	// vector<int> nums = {-1,0,1,2,-1,-1,-4};
	vector<int> nums = {0, 0, 1};
	Solution sol;

	print(sol.threeSum(nums));

}
