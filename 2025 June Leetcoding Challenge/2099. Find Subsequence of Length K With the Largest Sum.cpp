class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> index(n), ans(k);
        iota(index.begin(), index.end(), 0);

        sort(index.begin(), index.end(), [&](int a, int b){
            return nums[a] < nums[b];
        });

        sort(index.begin() + n - k, index.end());
        for(int i = n - k, j = 0; i < n; ++i, j++) ans[j] = nums[index[i]];
        return ans;
    }
};
