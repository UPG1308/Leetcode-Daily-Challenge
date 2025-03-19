class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; ++i){
            if(i + 2 < n && nums[i] == 0){
                ans++;
                nums[i] = 1;
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
            }
            else if(i + 3 >= n && nums[i] == 0) return -1;
        }
        return ans;
    }
};
