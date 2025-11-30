class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL) % p;

        if(sum == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = n, val = 0;
        for(int i = 0; i < n; ++i){
            val = (val + nums[i]) % p;
            if(mp.count((val - sum + p) % p)) ans = min(ans, i - mp[(val - sum + p) % p]);
            mp[val] = i;
        }
        return (ans == n)? -1: ans;
    }
};
