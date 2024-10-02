class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return {};
        vector<pair<int, int>> order;
        for(int i = 0; i < n; i++) order.push_back({arr[i], i});
        sort(order.begin(), order.end());
        vector<int> ans(n, 0);
        ans[order[0].second] = 1;
        for(int i = 1; i < n; i++){
            if(order[i].first == order[i - 1].first) ans[order[i].second] = ans[order[i - 1].second];
            else ans[order[i].second] = ans[order[i - 1].second] + 1;
        }
        return ans;
    }
};
