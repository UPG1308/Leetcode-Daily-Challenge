class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.rbegin(), happiness.rend());
        long long sum = 0;
        for(int i = 0; i < k && i < n; ++i){
            sum += max(0, happiness[i] - i);
        }
        return sum;
    }
};
