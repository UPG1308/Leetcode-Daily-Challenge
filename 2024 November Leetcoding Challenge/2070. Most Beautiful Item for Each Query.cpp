class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();
        sort(items.begin(), items.end(), [&](auto a, auto b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> indices(m, 0), ans(m,0);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b){
            if(queries[a] == queries[b]) return a < b;
            return queries[a] < queries[b];
        });
        
        int itemIndex = 0, maxBeauty = 0;
        for(int i = 0; i < m; ++i){
            int query = queries[indices[i]];
            int index = indices[i];

            while(itemIndex < n && items[itemIndex][0] <= query){
                maxBeauty = max(maxBeauty, items[itemIndex++][1]);
            }
            ans[index] = maxBeauty;
        }
        return ans;
    }
};
