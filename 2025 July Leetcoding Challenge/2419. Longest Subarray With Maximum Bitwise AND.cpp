class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxele = *max_element(nums.begin(), nums.end());
        int ans = 0, count = 0;
        for(int num: nums){
            if(num == maxele) count++;
            else count = 0;
            ans = max(ans, count);
        }
        return ans;
    }
};
