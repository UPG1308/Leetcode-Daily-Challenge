class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int cost = 0, len = 0;
        for(int start = 0, end = 0; end < n; end++){
            cost += abs(s[end] - t[end]);
            while(cost > maxCost){
                cost -= abs(s[start] - t[start]);
                start++;
            }
            len = max(len, end - start + 1);
        }
        return len;
    }
};
