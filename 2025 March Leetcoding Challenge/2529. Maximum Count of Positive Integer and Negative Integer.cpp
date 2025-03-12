class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int pos = nums.end() - lower_bound(nums.begin(), nums.end(), 1);
        int neg = upper_bound(nums.begin(), nums.end(), -1) - nums.begin();
        return max(pos, neg);
    }
};
