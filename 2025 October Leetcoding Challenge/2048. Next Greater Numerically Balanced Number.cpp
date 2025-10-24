class Solution {
public:
    bool isBalanced(int n){
        vector<int> freq(10);
        while(n){
            int ld = n % 10;
            freq[ld]++;
            n /= 10;
        }
        for(int i = 0; i < 10; ++i){
            if(freq[i] && freq[i] != i) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i = n + 1; i < 10000001; ++i){
            if(isBalanced(i)) return i;
        }
        return -1;
    }
};
