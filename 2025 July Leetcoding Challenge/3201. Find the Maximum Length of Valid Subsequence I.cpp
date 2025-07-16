class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int oddLen = 0, evenLen = 0, last = nums[0], len = 1;
        
        for(int num: nums){
            if(num % 2) oddLen++;
            else evenLen++;

            if(last % 2 != num % 2){
                len++;
                last = num;
            }
        }
        return max({evenLen, oddLen, len});
    }
};
