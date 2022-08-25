/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1 
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int l = 0;
		int r = height.size() - 1;
		int minHeight = min(height[l], height[r]);
		int maxArea = (r - l) * minHeight;
		while (l + 1 < r && l < r - 1) {
			if (height[l] < height[r])
				// move left pointer
				l++;
			else
				r--;
			int temp = (r - l) * min(height[l], height[r]);
			if (temp > maxArea) maxArea = temp;
		}

		return maxArea;
	}

};

int main() {
	vector<int> height = {1,8,6,2,5,4,8,3,7};
	Solution sol;

	cout << sol.maxArea(height);
}
