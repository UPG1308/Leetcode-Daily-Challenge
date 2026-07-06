class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<int> cur{-1, -1};
        int count = 0;

        sort(intervals.begin(), intervals.end(), [&](auto a, auto b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        for(auto it: intervals){
            if(it[1] > cur[1]) count++, cur = it;
        }
        return count;
    }
};
