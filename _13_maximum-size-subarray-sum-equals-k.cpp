class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        long long prefixSum = 0;
        long long longest = 0;
        unordered_map<long long, long long> indices;
        
        for (int i=0; i<nums.size(); ++i) {
            prefixSum += nums[i];
            if (prefixSum == k) {
                longest = i + 1;
            }
            if (indices.find(prefixSum - k) != indices.end()) {
                longest = max(longest, i - indices[prefixSum - k]);
            }
            //if (!indices.count(prefixSum)) {
            if (indices.find(prefixSum) == indices.end()) {
                indices[prefixSum] = i;
            }
        }
        return longest;
    }
};
// 6  5 6  1 3
// q
// 1  0 5  3 6

