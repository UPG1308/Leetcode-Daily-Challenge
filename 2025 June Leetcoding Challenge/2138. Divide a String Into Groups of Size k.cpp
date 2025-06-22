class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        int n = s.size();
        int rem = (k - n % k) % k;
        string extra(rem, fill);
        vector<string> ans;
        for(int i = 0; i < n; i += k){
            ans.push_back(s.substr(i, k));
        }
        if(rem) ans.back() += extra;
        return ans;
    }
};
