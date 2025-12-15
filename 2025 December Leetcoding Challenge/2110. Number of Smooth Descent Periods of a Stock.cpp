class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long count = 0, cnt = 1;

        for(int i = 1; i <= n; ++i){
            if(i != n && prices[i - 1] - 1 == prices[i]) cnt++;
            else {
                count = count + 1LL * cnt * (cnt + 1)/2;
                cnt = 1;
            }
        }
        return count;
    }
};
