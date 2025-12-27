class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> rooms(n);
        using T = pair<long long, long long>;
        priority_queue<T, vector<T>, greater<T>> roomsOccupied, roomsAvailable;

        for(int i = 0; i < n; ++i){
            roomsOccupied.push(make_pair(0, i));
        }

        for(auto it: meetings){
            int s = it[0], e = it[1];
            
            while(!roomsOccupied.empty() && (roomsOccupied.top().first <= s 
            || roomsAvailable.empty())){

                auto [freeTime, roomId] = roomsOccupied.top();
                roomsAvailable.push(make_pair(roomId, freeTime));
                roomsOccupied.pop();
            }            

            auto [roomId, freeTime] = roomsAvailable.top();
            roomsAvailable.pop();
            roomsOccupied.push({fmaxl(s, freeTime) + e - s, roomId});
            rooms[roomId]++;
        }

        int mx = -1, room = -1;
        for(int i = 0; i < n; ++i){
            if(mx < rooms[i]){
                mx = rooms[i];
                room = i;
            }
        }
        return room;
    }
};
