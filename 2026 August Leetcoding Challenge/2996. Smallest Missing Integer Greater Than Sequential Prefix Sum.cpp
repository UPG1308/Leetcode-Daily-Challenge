class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for(int i = 1; i < n; ++i){
            if(nums[i] == nums[i - 1] + 1) sum += nums[i];
            else break;
        }
        set<int> st(nums.begin(), nums.end());
        for(int j = sum; j <= 1e5; ++j){
            if(!st.count(j)) return j;
        }
        return -1;
    }
};
