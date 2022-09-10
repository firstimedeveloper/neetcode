class Solution {
public:
    int search(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size();
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (target == nums[mid])
				return mid;
			if (nums[l] <= nums[mid]) {
				if (target > nums[mid])
					l = mid + 1;
				else if (target < nums[l])
					l = mid + 1;
				else
					r = mid;
			} else {
				if (target < nums[mid])
					r = mid;
				else if (target > nums[r-1])
					r = mid;
				else
					l = mid + 1;
			}
		}
		return -1;
    }
};
