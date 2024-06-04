class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(256, 0);
        int one = 0, count = 0;
        for(char c: s) freq[c]++;
        for(int i: freq){
            if(i%2 == 1) one = 1;
            if(i != 0) count += (i / 2) * 2;
        }
        return count + one;
    }
};
