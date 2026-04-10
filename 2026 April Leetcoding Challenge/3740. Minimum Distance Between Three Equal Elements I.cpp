class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> mp;

        for(int i = 0; i < n; ++i) mp[nums[i]].push_back(i);

        int ans = 1e9;
        for(auto [_, it]: mp){
            if(it.size() <= 2) continue;
            for(int i = 0; i + 2 < it.size(); ++i) ans = min(ans, 2 * (it[i + 2] - it[i]));
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};
