class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxval = -1e8, valueJ = values[0];
        for(int i = 1; i < n; ++i){
            maxval = max(maxval, values[i] - i + valueJ);
            valueJ = max(valueJ, i + values[i]);
        }
        return maxval;
    }
};
