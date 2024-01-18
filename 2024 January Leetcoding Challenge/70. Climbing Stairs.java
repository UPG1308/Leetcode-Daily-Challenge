class Solution {
    int []dp;
    public int climbStairs(int n) {
        dp = new int[n + 1];
        // Arrays.fill(dp, -1);
        dp[0] = 1;
        for(int ind = 1; ind <= n; ind++){
            int oneStep = dp[ind - 1];
            int twoStep = 0;
            if(ind > 1)
                twoStep = dp[ind - 2];
            dp[ind] = oneStep + twoStep;
        }
        return dp[n];
    }
    public int helper(int ind){
        if(ind == 0) return 1;
        if(dp[ind] != -1) return dp[ind];
        int oneStep = helper(ind - 1);
        int twoStep = 0;
        if(ind > 1)
            twoStep = helper(ind - 2);
        return dp[ind] = oneStep + twoStep;
    }
}
