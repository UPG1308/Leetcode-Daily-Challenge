class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0, hasZero = 0, maxlen = 0;
        for(int begin = 0, end = 0; end < n; ++end){
            zeroCount += (nums[end] == 0)?1:0;
            if(zeroCount) hasZero = 1;
            while(zeroCount > 1){
                zeroCount -= (nums[begin++] == 0)?1:0;
            }
            maxlen = max(maxlen, end - begin);
        }
        if(!hasZero) return n - 1;
        return maxlen;
    }
};
