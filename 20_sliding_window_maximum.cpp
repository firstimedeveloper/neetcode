/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	/*
	 *
	 * Using a monotonic queue, where the elements inside the queue are in decreasing order.
	 * loop r is less than len(nums):
	 * 	loop q is not empty and current r is greater than back of q:
	 * 		pop q
	 * 	push r idx to q.
	 * 	if l idx is greater than front of q:
	 * 		pop front of q.
	 *
	 * 	if r+1 >= k:
	 * 		push_back front of q to ret
	 * 		incr l
	 * 	incr r
	 *
	 */
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> q;
		vector<int> ret;
		int l = 0; 
        int r = 0;

		while (r < nums.size()) {
			while (!q.empty() && nums[q.back()] < nums[r])
				q.pop_back();
			q.push_back(r);

			if (l > q.front())
				q.pop_front();

			if (r + 1 >= k) {
				ret.push_back(nums[q.front()]);
                l++;
			}
            r++;
		}
		return ret;
	}

};
