class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int lastDay = days[n - 1];
        vector<int> dp(lastDay + 2, 0);
        int i = 0;
        for(int day = 1; day <= lastDay; ++day){
            if(day < days[i]) dp[day] = dp[day - 1];
            else{
                ++i;
                dp[day] = min({costs[0] + dp[day - 1], dp[max(0, day - 7)] + costs[1], dp[max(0, day - 30)] + costs[2]});
            }
        }
        return dp[lastDay];
    }
};  
