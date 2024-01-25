class Solution {
    
    public int longestCommonSubsequence(String text1, String text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        int dp[][] = new int[l1 + 1][l2 + 1];
        // for(int[] i: dp)Arrays.fill(i, -1);
        
        for(int ind1 = 1; ind1 <= l1; ind1++){
            for(int ind2 = 1; ind2 <= l2; ind2++){
                if(text1.charAt(ind1 - 1) == text2.charAt(ind2 - 1)){
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }
                else dp[ind1][ind2] = Math.max(dp[ind1 - 1][ind2] ,dp[ind1][ind2 - 1]);
            }
        }

        return dp[l1][l2];
    }

    public int func(int ind1, int ind2, String text1, String text2, int[][] dp){
        if(ind1 < 0 || ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(text1.charAt(ind1) == text2.charAt(ind2)){
            return dp[ind1][ind2] = 1 + func(ind1 - 1, ind2 - 1, text1, text2, dp);
        }
        return dp[ind1][ind2] = Math.max(func(ind1 - 1, ind2, text1, text2, dp),func(ind1, ind2 - 1, text1, text2, dp));
    }
}
