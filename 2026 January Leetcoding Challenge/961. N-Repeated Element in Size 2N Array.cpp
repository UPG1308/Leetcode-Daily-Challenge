class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for(int k = 1; k <= 3; ++k){
            for(int i = 0; i < n - k; ++i){
                if(nums[i] == nums[i + k]) return nums[i];
            }
        }
        return -1;
    }
};
