/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
	int	longestConsecutive(vector<int>& nums) {
		// vector<vector<int>> sequences;
		unordered_set<int> nums_set(nums.begin(), nums.end());
		int max = 0;

		for (auto i = nums.begin(); i != nums.end(); ++i) {
			if (!nums_set.count(*i-1)) {
				vector<int> temp;
				int j = 0;
				while (nums_set.count(*i+j)) ++j;
				if (j > max)
					max = j;
			}

		}
		return max;
	}

};

int main() {
	// vector<int> nums = {100,4,200,1,3,2};
	vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
	Solution sol;
	cout << sol.longestConsequtive(nums);
}
