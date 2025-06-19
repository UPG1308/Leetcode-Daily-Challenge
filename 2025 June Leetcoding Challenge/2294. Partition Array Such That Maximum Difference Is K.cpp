class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int count = 0, it = 0;
        
        while(it != nums.size()){
            it = upper_bound(nums.begin(), nums.end(), nums[it] + k) - nums.begin();
            count++;
        }
        return count;
    }
};
