/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		vector<int> ret;

		for (size_t i=0; i<nums.size()-1; ++i) {
			int find = target - nums[i];
			int left = i + 1;
			int right = nums.size();
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (find == nums[mid]) {
					ret.push_back(i + 1);
					ret.push_back(mid + 1);
					return ret;
				}
				if (find < nums[mid])
					right = mid;
				else
					left = mid + 1;

			}
		}
		return ret;
	}
};

void print_vector(vector<int> nums) {
	cout << "[ ";
	for (auto num: nums)
		cout << num << " ";
	cout << "]\n";
}

int main() {
	vector<int> nums = {2, 7, 11, 15};
	int target = 9;

	// vector<int> nums = {2,3,4};
	// int target = 6;

	//vector<int> nums = {-1, 0};
	//int target = -1;

	Solution sol;

	print_vector(sol.twoSum(nums, target));
}
