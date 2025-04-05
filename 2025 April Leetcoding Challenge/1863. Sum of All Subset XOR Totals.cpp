class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int mask = 1; mask < (1 << n); ++mask){
            int result = 0;
            for(int i = 0; i < n; ++i){
                if((mask & (1 << i))){
                    result ^= nums[i];
                }
            }
            sum += result;
        }
        return sum;
    }
};
