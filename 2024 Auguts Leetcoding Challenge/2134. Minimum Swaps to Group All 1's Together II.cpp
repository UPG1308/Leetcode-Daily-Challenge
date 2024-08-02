class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for(int i: nums) count += (i == 1)?1:0;
        int oneCount = 0, mn = count;
        for(int i = 0; i < count; i++) oneCount += (nums[i] == 1)?1:0;
        for(int i = count; i < n + count; i++){
            oneCount += (nums[i%n] == 1)?1:0;
            oneCount -= (nums[(i - count)%n] == 1)?1:0;
            mn = min(mn, count - oneCount);
        }
        return mn;
    }
};
