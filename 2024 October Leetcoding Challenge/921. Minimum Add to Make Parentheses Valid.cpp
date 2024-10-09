class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, bal = 0;
        for(char c: s){
            bal += c == '('?1:-1;
            if(bal == -1){
                ans++;
                bal++;
            }
        }
        return ans + bal;
    }
};
