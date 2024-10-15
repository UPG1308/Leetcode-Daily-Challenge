class Solution {
public:
    long long minimumSteps(string s) {
        long long one = 0, zero = 0, count = 0;
        for(char c: s){
            if(c == '1') one++;
            else count += one;
        }
        return count;
    }
};
