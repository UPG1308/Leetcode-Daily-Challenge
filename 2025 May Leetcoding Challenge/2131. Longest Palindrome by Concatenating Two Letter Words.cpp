class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;

        for(string s: words) mp[s]++;
        int count = 0, same = 0, diffCount = 0;
        for(auto [s, c]: mp){
            if(s[0] == s[1]) count += (c/2) * 4, same |= (1 & c);
            else {
                string t = s;
                reverse(t.begin(), t.end());
                if(mp.count(t)) diffCount += min(c, mp[t]) * 2;
            }
        }
        return count + same * 2 + diffCount;
    }
};
