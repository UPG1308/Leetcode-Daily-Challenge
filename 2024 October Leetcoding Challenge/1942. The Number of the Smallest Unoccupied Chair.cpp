class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int arrivalTime = times[targetFriend][0];
        sort(times.begin(), times.end());
        priority_queue<int, vector<int>, greater<int>> smallestAvailable;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> endTime;
        int line = 0;
        for(vector<int> time: times){
            int arrive = time[0], depart = time[1];
            while(!endTime.empty() and endTime.top().first <= arrive) {
                smallestAvailable.push(endTime.top().second);
                endTime.pop();
            }
            if(!smallestAvailable.empty()){
                int chairNo = smallestAvailable.top();
                smallestAvailable.pop();
                if(arrive == arrivalTime) return chairNo;
                endTime.push({depart, chairNo});
            }
            else{
                if(arrive == arrivalTime) return line;
                endTime.push({depart, line++});
            }
        }
        return 0;
    }
};
