class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q(gifts.begin(), gifts.end());
        while(!q.empty() && k--){
            int top = q.top();
            q.pop();
            q.push(sqrt(top));
        }
        long long ans = 0;
        while(!q.empty()){
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};
