class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> mp;
        vector<long long> ans(n);

        for(int i = 0; i < n; ++i){
            mp[nums[i]].push_back(i);
        }

        for(auto [_, v]: mp){
            int m = v.size();
            vector<long long> p(m + 1);
            for(int i = 0; i < m; ++i){
                p[i + 1] = p[i] + v[i];
            }
            for(int i = 0; i < m; ++i){
                long long left = 1LL * i * v[i] - p[i];
                long long righ = (p[m] - p[i + 1]) - (m - i - 1LL) * v[i];
                ans[v[i]] = left + righ;
            }
        }
        return ans;
    }
};
