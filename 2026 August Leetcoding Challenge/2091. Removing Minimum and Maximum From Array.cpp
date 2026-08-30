class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int mn = min_element(nums.begin(), nums.end()) - nums.begin();
        int mx = max_element(nums.begin(), nums.end()) - nums.begin();
        if(mn > mx) swap(mn, mx);
        return min({mx + 1, n - mn, mn + 1 + n - mx});
    }
};
