class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret(nums.size());
        int l = 0;
        int n = nums.size();
        int r = n - 1;
        
        for (int i=n-1; i>=0; --i) {
            int temp;
            if (abs(nums[l]) < abs(nums[r])) {
                temp = nums[r];
                r--;
            } else {
                temp = nums[l];
                l++;
            }
            ret[i] = temp * temp;
        }
                    
        return ret;
    }
};
