class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt = count(s.begin(), s.end(), '1');
        int extra = 0, zeroCnt = 0;
        vector<int> zeros;
        for(char c: s){
            if(c == '0') zeroCnt++;
            else if (zeroCnt){
                zeros.push_back(zeroCnt);
                zeroCnt = 0;
            }
        }
        if(zeroCnt) zeros.push_back(zeroCnt);

        for(int i = 1; i < zeros.size(); ++i){
            extra = max(extra, zeros[i - 1] + zeros[i]);
        }
        return cnt + extra;
    }
};
