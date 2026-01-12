class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        auto dist = [&](auto a, auto b){
            int c = abs(a[0] - b[0]), d = abs(a[1] - b[1]);
            return max(c, d);
        };

        int ans = 0;
        for(int i = 1; i < n; ++i){
            ans += dist(points[i - 1], points[i]);
        }
        return ans;
    }
};
