class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1);
        for(int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + (isVowel(words[i][0]) && isVowel(words[i].back()));

        vector<int> ans;
        for(vector<int> q: queries){
            ans.push_back(prefix[q[1] + 1] - prefix[q[0]]);
        }
        return ans;
    }
};
