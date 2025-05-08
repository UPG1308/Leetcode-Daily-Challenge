class Solution {
public:

    bool boundaryCheck(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();

        vector<vector<long long>> dist(n, vector<long long>(m, 1e18));
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        dist[0][0] = 0;
        pq.push({dist[0][0], 0, 0, 2});

        int delRow[] = {+1, 0, -1, 0};
        int delCol[] = {0, -1, 0, +1};
        while(!pq.empty()){
            auto topNode = pq.top();
            pq.pop();

            int row = topNode[1], col = topNode[2], moves = topNode[3];
            int nextMove = moves == 2? 1: 2;
            for(int i = 0; i < 4; ++i){
                int r = row + delRow[i];
                int c = col + delCol[i];

                if(boundaryCheck(r, c, n, m) && dist[r][c] > fmaxl(dist[row][col], moveTime[r][c]) + nextMove){
                    dist[r][c] = fmaxl(dist[row][col], moveTime[r][c]) + nextMove;
                    pq.push({dist[r][c], r, c, nextMove});
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};
