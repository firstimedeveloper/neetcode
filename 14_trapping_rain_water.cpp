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

		int l = 0;
		int r = height.size()-1;
		int lmax = height[l];
		int rmax = height[r];
		while (l < r) {
			if (lmax <= rmax) {
				l++;
				total += max(0, lmax - height[l]);
				lmax = max(lmax, height[l]);
			} else {
				r--;
				total += max(0, rmax - height[r]);
				rmax = max(rmax, height[r]);
			}


		}
		return total;
	}
};
// lmax: 0 1
// rmax: 1
//	  l: 1
//	  r: 2

int main() {
	Solution sol;
	vector<int> height;
	height = {4,2,0,3,2,5}; 
	//        0 0 1 1 2 2 2 2 3 3 3 3
	//        3 3 3 3 3 3 3 2 2 2 1 0
	//height = {0,1,0,2,1,0,1,3,2,1,2,1};
	//height = {4,2,3};
	cout << sol.trap(height);
}
