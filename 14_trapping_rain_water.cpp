/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/

#include <bits/stdc++.h>

using namespace std;

void print(vector<int> nums) {
	cout << "[ ";
	for (auto i: nums) 
		cout << i << " ";
	cout << "]\n";
}

class Solution {
public:
	int trap(vector<int>& height) {
		int total = 0;
		vector<int> max_left;
		vector<int> max_right;
		vector<int> min_lr;

		int max_height = 0;
		for (auto i=height.begin(); i != height.end(); ++i) {
			max_left.push_back(max_height);
			max_height = max(max_height, *i);
		}
		max_height = 0;
		for (auto i=height.rbegin(); i != height.rend(); ++i) {
			max_right.push_back(max_height);
			max_height = max(max_height, *i);
		}
		for (size_t i=0; i<height.size(); ++i) {
			min_lr.push_back(min(max_left[i], max_right[height.size() - i - 1]));
		}
		for (size_t i=0; i<height.size(); ++i) {
			total += max(0, min_lr[i] - height[i]);
		}
		print(height);
		print(max_left);
		print(vector<int>{max_right.rbegin(), max_right.rend()});
		print(min_lr);
		return total;
	}
};
// 0 > 1 FALSE
// 1 > 0 True
// 	1

int main() {
	Solution sol;
	vector<int> height;
	// height = {4,2,0,3,2,5}; 
	height = {0,1,0,2,1,0,1,3,2,1,2,1};
	//height = {4,2,3};
	cout << sol.trap(height);
}
