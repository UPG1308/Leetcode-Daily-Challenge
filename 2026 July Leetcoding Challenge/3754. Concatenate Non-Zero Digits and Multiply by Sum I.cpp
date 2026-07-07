class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long sum = 0, val = 0;
        for(char c: s){
            if(c == '0') continue;
            sum += (c - '0');
            val = val * 10 + (c - '0');
        }
        return val * sum;
    }
};
