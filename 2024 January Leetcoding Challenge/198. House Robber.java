class Solution {
    public int rob(int[] nums) {
        int n = nums.length,  dp[] = new int[nums.length]; dp[0] = nums[0];
        if(n > 1)dp[1] = Math.max(nums[1],nums[0]);
        for(int i = 2; i < n; i++){
            dp[i] = Math.max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
}
