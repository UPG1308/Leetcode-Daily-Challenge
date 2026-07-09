class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> parent(n);
        int par = 0;
        for(int i = 0, j = 0; i < n && j < n; ++i){
            if(i > j) parent[i] = par = i;
            while(j + 1 < n && abs(nums[i] - nums[j + 1]) <= maxDiff){
                parent[j + 1] = par;
                j++;
            }
        }

        int q = queries.size();
        vector<bool> ans(q);
        for(int i = 0; i < q; ++i){
            int l = queries[i][0], r = queries[i][1];
            ans[i] = parent[l] == parent[r];
        }
        return ans;
    }
};
