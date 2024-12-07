class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        auto isMaximumPossible = [&](int mid){
            int operationsNeeded = 0;
            for(int num: nums) operationsNeeded += (num - 1)/mid;
            return operationsNeeded <= maxOperations;
        };

        int low = 1, high = 1e9, ans = 1e9;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isMaximumPossible(mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
