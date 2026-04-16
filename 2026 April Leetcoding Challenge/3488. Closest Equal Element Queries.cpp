class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int q = queries.size(), n = nums.size();
        map<int, vector<int>> mp;
        vector<int> ind(n), answ(q, -1);

        for(int i = 0; i < n; ++i){
            ind[i] = mp[nums[i]].size();
            mp[nums[i]].push_back(i);
        }

        for(int i = 0; i < q; ++i){
            int num = nums[queries[i]];
            int index = ind[queries[i]];
            int len = mp[num].size();
            
            if(len == 1) continue;
            int ans = 1e9;
            if(index != 0) ans = min(ans, abs(mp[num][index] - mp[num][index - 1]));
            else ans = min(ans, n - (mp[num].back() - mp[num][0]));
            
            if(index != len - 1) ans = min(ans, abs(mp[num][index] - mp[num][index + 1]));
            else ans = min(ans, n - (mp[num].back() - mp[num][0]));
            answ[i] = ans;
        }
        return answ;
    }
};
