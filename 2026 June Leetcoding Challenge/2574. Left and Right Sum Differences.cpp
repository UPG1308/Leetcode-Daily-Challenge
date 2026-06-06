class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> R(n + 1);

        for(int i = n - 1; i >= 0; --i){
            R[i] = R[i + 1] + nums[i];
        }

        vector<int> ans(n);
        int sum = 0;
        for(int i = 0; i < n; ++i){
            ans[i] = abs(sum - R[i + 1]);
            sum += nums[i];
        }

        return ans;
    }
};
