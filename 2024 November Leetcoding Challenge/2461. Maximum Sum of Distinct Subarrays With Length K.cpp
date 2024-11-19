class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<long long, long long> mp;
        long long sum = 0, maxSum = 0;
        for(int begin = 0, end = 0; end < n; ++end){
            sum += nums[end];
            mp[nums[end]]++;

            while(end - begin + 1 > k || mp.size() != end - begin + 1){
                sum -= nums[begin];
                mp[nums[begin]]--;
                if(mp[nums[begin]] == 0) mp.erase(nums[begin]);
                begin++;
            }
            if(end - begin + 1 == k) maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
