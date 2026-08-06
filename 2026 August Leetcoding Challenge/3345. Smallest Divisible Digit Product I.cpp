class Solution {
public:
    int smallestNumber(int n, int t) {
        
        for(int i = n; i <= 100; ++i){
            int num = i, ans = 1;
            while(num){
                ans *= (num % 10);
                num /= 10;
            }
            if(ans % t == 0) return i;
        }
        return -1;
    }
};
