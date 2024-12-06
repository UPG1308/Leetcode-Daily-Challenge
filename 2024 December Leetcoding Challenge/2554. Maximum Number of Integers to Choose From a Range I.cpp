class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(), banned.end());
        long long sum = 0;
        int count = 0;
        for(int i = 1; i <= n; ++i){
            if(st.find(i) != st.end()) continue;
            if(sum + i > maxSum) break;
            sum += i;
            count++;
        }
        return count;
    }
};