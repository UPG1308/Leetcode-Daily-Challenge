class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), q = queries.size();
        vector<int> prefix(n + 1,0), ans(q, 0);
        for(int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] ^ arr[i];
        for(int i = 0; i < q; ++i){
            int l = queries[i][0], r = queries[i][1];
            ans[i] = prefix[r + 1] ^ prefix[l];
        }
        return ans;
    }
};
