class Solution {
public:
	// Implement a binary search where left = 0, right is the size of the nums vector
	// since we know the range of the nums is not changed, only the starting point.
	// We only nee to find the starting point of the nums vector to be able to shift
	// when indexing the nums vector.
	//
	// first find the k, starting point of the sorted array.
	// use the generic binary search template, except when indexing from the nums vector,
	// use the formula nums[(mid + k) % nums.size()].
	// since this will find the actual value we're looking for.
    int search(vector<int>& nums, int target) {
		int k = 0;
		int prev = nums[0];
		for (int i=1; i<nums.size(); ++i) {
			if (prev > nums[i]) {
				k = i;
				break ;
			}
		}

		int left = 0;
		int right = nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[(mid + k) % nums.size()] == target)
				return (mid + k) % nums.size();
			if (nums[(mid + k) % nums.size()] < target)
				left = mid + 1;
			else
				right = mid;

		}
        return -1;
    }
};
