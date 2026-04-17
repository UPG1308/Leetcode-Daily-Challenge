class Solution {
public:
    int reverse(int num){
        int ans = 0;
        while(num){
            int ld = num % 10;
            ans = ans * 10 + ld;
            num /= 10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size(), ans = 1e9;
        map<int, int> mp;
        for(int i = 0; i < n; ++i){
            if(mp.count(nums[i])) ans = min(ans, i - mp[nums[i]]);
            mp[reverse(nums[i])] = i;
        }

        return ans == 1e9? -1: ans;
    }
};
