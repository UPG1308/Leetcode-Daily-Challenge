class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        int left = 0, right = 0;
        while(left < n && right < n){
            while(right + 1 < n && nums[right] + 1 == nums[right + 1]) right++;
            int i = right;
            while(i - left + 1 >= k) ans[(i--) - k + 1] = nums[i];
            left = ++right;
        }
        return ans;
    }
};
