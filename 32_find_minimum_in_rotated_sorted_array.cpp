class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() -1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            cout << nums[mid];
            if (mid != 0 && nums[mid-1] > nums[mid])
                return nums[mid];
            if (nums[l] <= nums[mid]) {
                if (nums[l] < nums[r])
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                r = mid;
                
            }
        }
        return nums[l];
    }
};
