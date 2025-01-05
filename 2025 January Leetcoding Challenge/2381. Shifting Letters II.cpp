class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);
        for(vector<int> shift: shifts){
            diff[shift[0]] += (shift[2] == 1)?1:-1;
            diff[shift[1] + 1] += (shift[2] == 1)? -1:1;
        }

        for(int i = 1; i < diff.size(); ++i) diff[i] += diff[i - 1];

        string str = "";
        for(int i = 0; i < s.size(); ++i){
            int ch = s[i] - 'a';            
            str.push_back(char(((ch + diff[i]) % 26 + 26) % 26 + 'a'));
        }
        return str;
    }
};
