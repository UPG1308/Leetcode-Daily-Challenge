class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b){
            int la = __builtin_popcount(a);
            int lb = __builtin_popcount(b);
            if(la == lb) return a < b;
            return la < lb;
        });
        return arr;
    }
};
