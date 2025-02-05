class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), count = 0;
        for(int i = 0; i < n; ++i) count += s1[i] != s2[i];
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2 && count <= 2;
    }
};
