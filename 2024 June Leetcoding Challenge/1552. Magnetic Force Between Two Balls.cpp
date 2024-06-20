class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 0, high = position[n - 1];
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, position, m)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
    bool isPossible(int dis, vector<int>& position, int m){
        int lastPicked = -1, count = 0;
        for(int i = 0; i < position.size(); i++){
            if(lastPicked == -1 || abs(position[i] - position[lastPicked]) >= dis){
                count++;
                lastPicked = i;
            }
        }
        return count >= m;
    }
};
