class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; ++i){
            int cnt = 0;
            for(int j = i; j < n; ++j){
                cnt += (nums[j] == target)? +1: -1;
                count += cnt > 0;
            }
        }
        return count;
    }
};
