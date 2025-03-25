class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> xaxis, yaxis;
        for(vector<int> rec: rectangles){
            xaxis.push_back({rec[0], rec[2]});
            yaxis.push_back({rec[1], rec[3]});
        }
        sort(xaxis.begin(), xaxis.end());
        sort(yaxis.begin(), yaxis.end());
        int xcuts = countCuts(xaxis);
        int ycuts = countCuts(yaxis);
        return xcuts >= 3 || ycuts >= 3;
    }

    int countCuts(vector<pair<int, int>>& axis){
        int cuts = 0, end = -1;
        for(pair<int, int> point: axis){
            if(point.first >= end) cuts++;
            end = max(end, point.second);
        }
        return cuts;
    }
};
