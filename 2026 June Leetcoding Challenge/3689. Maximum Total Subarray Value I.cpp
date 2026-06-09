class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mn = INT_MAX, mx = INT_MIN;
        for(int x: nums){
            mn = fminl(x, mn);
            mx = fmaxl(x, mx);
        }
        return (mx - mn) * k;
    }
};
