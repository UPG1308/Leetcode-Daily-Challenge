class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        using ll = long long;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int i: nums) pq.push(i);

        int ops = 0;
        while(pq.size() >= 2 && pq.top() < k){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            pq.push(min(x, y) * 2LL + max(x, y));
            ops++;
        }
        return ops;
    }
};
