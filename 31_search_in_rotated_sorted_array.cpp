class Solution {
public:
	// binary search
	// if L <= M
	// 		if target > M or target < L
	// 			search right (l = mid + 1)
	// else
    int search(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (target == nums[mid])
				return mid;
			if (nums[l] <= nums[mid]) {
				if (target > nums[mid] || target < nums[l])
					l = mid + 1;
				else
					r = mid - 1;
			} else {
				if (target < nums[mid] || target > nums[r])
					r = mid - 1;
				else
					l = mid + 1;
			}
		}
		return -1;
    }
};
