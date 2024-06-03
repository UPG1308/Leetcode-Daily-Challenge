class Solution {
public:    
    int appendCharacters(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        int i = 0, j = 0;
        while(i < n1 && j < n2){
            if(s[i] == t[j]) j++;
            i++;
        }
        return n2 - j;         
    }
};
