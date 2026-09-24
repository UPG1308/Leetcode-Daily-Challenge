class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        auto digitsum = [&](int num){
            int sum = 0;
            while(num){
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };
        for(int i = 0; i < n; ++i){
            if(digitsum(nums[i]) == i) return i;
        }
        return -1;
    }
};
