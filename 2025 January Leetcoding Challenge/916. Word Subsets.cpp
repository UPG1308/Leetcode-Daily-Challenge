class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        auto count = [&](string& s){
            vector<int> ar(26);
            for(char c: s) ar[c - 'a']++;
            return ar;
        };
        
        vector<int> freq(26, 0);
        for(string s: words2){
            vector<int> arr = count(s);
            for(int i = 0; i < 26; ++i) freq[i] = max(freq[i], arr[i]);
        }

        auto isGood = [&](vector<int>& a){
            for(int i = 0; i < 26; ++i){
                if(freq[i] > a[i]) return false;
            }
            return true;
        };

        vector<string> ans;
        for(string s: words1){
            vector<int> w1 = count(s);
            if(isGood(w1)) ans.push_back(s);
        }
        return ans;
    }
};
