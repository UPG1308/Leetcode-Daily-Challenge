class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int ,int> mp;
        mp[0] = 1;
        int rem = 0, count = 0;
        for(int i = 0; i < n; i++){
            rem = (rem + nums[i]%k + k) % k;
           if(mp.find(rem) != mp.end()) count += mp[rem];
            mp[rem]++;            
        }
        return count;
    }
};
