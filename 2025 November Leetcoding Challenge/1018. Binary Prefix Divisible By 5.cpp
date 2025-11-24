class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n);
        int pref = 0;
        for(int i = 0; i < n; ++i){
            pref <<= 1;
            pref += nums[i];
            pref %= 5;
            ans[i] = pref % 5 == 0;
        }
        return ans;
    }
};
