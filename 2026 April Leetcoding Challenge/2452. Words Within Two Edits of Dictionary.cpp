class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(auto &s: queries){
            for(auto &t: dictionary){
                int edits = 0;
                for(int i = 0; i < s.size(); ++i){
                    edits += (s[i] != t[i]);
                    if(edits > 2) break;
                }
                if(edits <= 2) {
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};
