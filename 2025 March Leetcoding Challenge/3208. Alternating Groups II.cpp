class Solution {
public:
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    int countPatterns(string s, int k){
        vector<int> lps = prefix_function(s);
        int count = 0;
        for(int i = k; i < lps.size(); i++){
            if(lps[i] == k) count++;
        }
        return count;
    }
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        colors.insert(colors.end(), colors.begin(), colors.begin() + k - 1);
        string text = "";
        for(int i: colors) text.append(to_string(i));
        string pat1 = "";
        string pat2 = "";
        for(int i = 0; i < k; i++){
            if(i&1){
                pat1 += '0';
                pat2 += '1';
            }
            else {
                pat1 += '1';
                pat2 += '0';
            }
        }
        int count = 0;
        count += countPatterns(pat1 + "#"+ text, k);
        count += countPatterns(pat2 + "#"+ text, k);
        return count;
    }
};
