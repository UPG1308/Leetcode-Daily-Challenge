class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string& s: words){
            int cnt = 0;
            for(char c: s) cnt += (weights[c - 'a']);
            cnt %= 26;
            ans += 'z' - cnt;
        }
        return ans;
    }
};
