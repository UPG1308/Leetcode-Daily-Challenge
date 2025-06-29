class Solution {
public:
    int MOD = 1e9 + 7;

    long long binpow(long long a, int b){
        long long ans = 1;
        if(b < 0) return 0;
        while(b){
            if(b & 1) ans = ans * a % MOD;
            a = a * a % MOD;
            b = b >> 1;
        }
        return ans;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long count = 0;
        for(int i = 0, j = n - 1; i <= j; ++i){
            while(i <= j && nums[i] + nums[j] > target) j--;
            count = (count + binpow(2, j - i)) % MOD;
        }
        return count;
    }
};
