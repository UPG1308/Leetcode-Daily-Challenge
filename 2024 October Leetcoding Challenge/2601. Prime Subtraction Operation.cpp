class Solution {
public:
    auto generatePrimes(int n){
        vector<bool> primes(n + 1, true);
        for(int i = 2; i * i <= n; ++i){
            for(int j = 2 * i; j <= n; j += i){
                primes[j] = false;
            }
        }
        set<int> st;
        for(int i = 2; i <= n; ++i){
            if(primes[i]) st.insert(i);
        }
        return st;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end());
        set<int> st = generatePrimes(mx);

        for(int i = n - 2; i >= 0; --i){
            if(nums[i] < nums[i + 1]) continue;
            int diff = nums[i] - nums[i + 1];
            auto it = st.upper_bound(diff);
            if(it == st.end()) return false;
            nums[i] -= *it;
            if(nums[i] <= 0) return false;
        }
        return true;
    }
};
