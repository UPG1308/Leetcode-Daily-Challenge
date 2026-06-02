class Solution {
public:
    int calculate(vector<int>& start1, vector<int>& duration1, vector<int>& start2, vector<int>& duration2){
        int finish = INT_MAX;
        for(int i = 0; i < start1.size(); ++i){
            finish = min(finish, start1[i] + duration1[i]);
        }
        int ans = INT_MAX;
        for(int i = 0; i < start2.size(); ++i){
            ans = min(ans, max(finish, start2[i]) + duration2[i]);
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(calculate(landStartTime, landDuration, waterStartTime, waterDuration), calculate(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};
