class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, n = arrays.size(), minVal = arrays[0][0], maxVal = arrays[0][arrays[0].size() - 1];
        for(int i = 1; i < arrays.size(); ++i){
            n = arrays[i].size();
            res = max({res, abs(arrays[i][n - 1] - minVal), abs(maxVal - arrays[i][0])});
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i][n - 1]);
        }
        return res;
    }
};
