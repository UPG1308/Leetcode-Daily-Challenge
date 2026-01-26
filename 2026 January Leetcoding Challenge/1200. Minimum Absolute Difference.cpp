class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());

        int diff = 1e9;
        for(int i = 1; i < n; ++i) diff = min(diff, a[i] - a[i - 1]);
        vector<vector<int>> ans;

        for(int i = 1; i < n; ++i){
            if(a[i] - a[i - 1] == diff) ans.push_back({a[i - 1], a[i]});
        }

        return ans;
    }
};
