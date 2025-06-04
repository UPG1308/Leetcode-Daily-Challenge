class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends == 1) return word;
        int maxlen = n - numFriends + 1;
        string s = "a";
        for(int i = 0; i < n; ++i){
            string str = word.substr(i, min(maxlen, n - i));
            if(str >= s) s = str;
        }
        return s;
    }
};
