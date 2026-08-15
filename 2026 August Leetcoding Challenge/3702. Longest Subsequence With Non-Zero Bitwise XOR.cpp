class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xor_val = 0, n = nums.size(), one = 0;
        for(int num: nums) xor_val ^= num, one |= num;
        if(one == 0) return 0;
        return xor_val? n: n - 1;
    }
};
