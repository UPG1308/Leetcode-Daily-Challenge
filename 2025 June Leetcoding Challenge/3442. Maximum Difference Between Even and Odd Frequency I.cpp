class Solution {
public:
    int maxDifference(string s) {
        map<int, int> freq;
        for(int i = 0; i < s.size(); ++i) freq[s[i] - 'a']++;

        int odd = 0, even = s.size();
        for(auto [_, v]: freq){
            if(v & 1) odd = max(odd, v);
            else even = min(even, v);
        }
        
        return odd - even;
    }
};
