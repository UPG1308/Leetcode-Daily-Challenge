class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int diff = 0;
        for(int i = 0; i < 2 * n; ++i){
            diff = max(diff, abs(nums[i % n] - nums[((i - 1) + n) % n]));
            diff = max(diff, abs(nums[i % n] - nums[((i + 1) % n)]));
        }
        return diff;
    }
};
