/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.



Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true


Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
		std::unordered_map<int, bool> num_map;;
		std::vector<int>::iterator it;

		for (it = nums.begin(); it != nums.end(); ++it) {
			if (num_map.count(*it) == 0) {
				// not found
				num_map[*it] = true;
			} else {
				// found
				return true;
			}

		}
		return false;
    }
};

int main() {
	std::vector<int> nums = {1, 2, 3, 4, 5, 1};

	Solution	sol;
	bool		ans;

	ans = sol.containsDuplicate(nums);
	std::cout << "solution: " << ans << std::endl;

	return 0;
}
