/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/

#include <bits/stdc++.h>

using namespace std;

void	print_vector(vector<int> const &vec) {
	cout << "[";
	for (auto &i: vec) {
		cout << " " << i << " ";
	}
	cout << "]\n";
}

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);

		int	prev;

		prev = 1;
		vector<int>::iterator i = ret.begin();
		for (auto it=nums.begin(); it!=nums.end(); ++it) {
			*i *= prev;
			prev *= *it;
			i++;
		}
		prev = 1;
		vector<int>::reverse_iterator j = ret.rbegin();
		for (auto it=nums.rbegin(); it!=nums.rend(); ++it) {
			*j *= prev;
			prev *= *it;
			j++;
		}

		return ret;
    }
};

int main() {
	vector<int> nums = {1,2,3,4};

	Solution sol;
	print_vector(sol.productExceptSelf(nums));
	return 0;
}
