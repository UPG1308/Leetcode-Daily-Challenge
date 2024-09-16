#define ll long long
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<ll> minutes;
        for(int i = 0; i < n; ++i){
            string s = timePoints[i];
            ll totalMinutes = stoi(s.substr(0, 2)) * 60ll + stoi(s.substr(3, 2));
            minutes.push_back(totalMinutes);
        }
        sort(minutes.begin(), minutes.end());
        int minDiff = 1e8;
        for(int i = 1; i < n; ++i) minDiff = min(minDiff * 1ll, minutes[i] - minutes[i - 1]);
        return min(minDiff * 1ll, 24 * 60ll - minutes[minutes.size() - 1] + minutes[0]);
        
    }
};
