class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int maxsum = nums[0];
        for(int i = 1; i < n; ++i){
            dp[i] = max(nums[i] + dp[i - 1], nums[i]);
            maxsum = max(maxsum, dp[i]);
        }
        int minsum = nums[0];
        dp[0] = nums[0];
        for(int i = 1; i < n; ++i){
            dp[i] = min(nums[i] + dp[i - 1], nums[i]);
            minsum = min(minsum, dp[i]);
        }
        // int minsum = dp[n - 1];
        return max(maxsum, abs(minsum));
    }
};
