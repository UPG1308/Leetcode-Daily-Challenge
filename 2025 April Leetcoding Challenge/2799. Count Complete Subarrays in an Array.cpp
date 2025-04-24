class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());
        int unique = 0, ans = 0;
        map<int, int> mp;
        for(int begin = 0, end = 0; end < n; ++end){
            unique += (++mp[nums[end]] == 1)? 1: 0;
            while(begin <= end && unique == st.size()){
                ans += n - end;
                unique -= (--mp[nums[begin++]] == 0)?1:0;
            }
        }
        return ans;
    }
};
