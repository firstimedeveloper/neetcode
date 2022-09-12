#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() -1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
			printf("%d %d %d\n", l, mid, r);
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

int main() {
	Solution sol;
	vector<int> nums = {4,5,6,7,0,1,2};
	cout << sol.findMin(nums);
}
