class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        unsigned long long len = 0, maxlen = 0;
        while(!st.empty()){
            int num = *st.rbegin();
            while(!st.empty()){
                if(st.find(num) == st.end()) break;
                len++;
                st.erase(num);
                long long sq = sqrt(num);
                if(sq * sq != num) break;
                num = sq;
            }
            maxlen = max(maxlen, len);
            len = 0;
        }
        return maxlen <= 1? -1: maxlen;
    }
};
