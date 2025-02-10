class Solution {
public:
    bool isLetter(char c){
        return c >= '0' && c <= '9';
    }
    string clearDigits(string s) {
        string str = "";
        int lettersCount = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            if(isLetter(s[i])) {
                lettersCount++;
                continue;
            }
            else if(lettersCount > 0){
                lettersCount--;
                continue;                
            }
            str = str + s[i];
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
