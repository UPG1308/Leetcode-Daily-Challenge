class Solution {
    int mod = (int) 1e9 + 7;
    public int checkRecord(int n) {
        long dp[][][] = new long[n + 2][4][3];
        for(int consecDay = 0; consecDay < 4; consecDay++){
            for(int absentDay = 0; absentDay < 3; absentDay++) dp[n + 1][consecDay][absentDay] = 1;
        }
        for(int day = n; day >= 1; day--){
            for(int consecDay = 2; consecDay >= 0; consecDay--){
                for(int absentDay = 2; absentDay >= 0; absentDay--){
                    long present = 0, late = 0, absent = 0;
                    present = dp[day + 1][0][absentDay];
                    if(absentDay == 0) absent = dp[day + 1][0][absentDay + 1];
                    if(consecDay < 2) late = dp[day + 1][consecDay + 1][absentDay];
                    dp[day][consecDay][absentDay] = (present % mod + absent % mod + late % mod) % mod;
                }
            }
        }
        return (int) dp[1][0][0];
    }
    //1 present 2 absent 3 late
    public long helper(int day, int consecDay, int absentDay, int n, long[][][] dp){
        if(day == n + 1) return 1;
        if(dp[day][consecDay][absentDay] != -1) return dp[day][consecDay][absentDay];
        long present = 0, late = 0, absent = 0;
        present = helper(day + 1, 0, absentDay, n, dp);
        if(absentDay == 0) absent = helper(day + 1, 0, absentDay + 1, n, dp);
        if(consecDay < 2) late = helper(day + 1, consecDay + 1, absentDay, n, dp);
        return dp[day][consecDay][absentDay] = (present % mod + absent % mod + late % mod) % mod;
    }
}
