class Solution {
public:
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
