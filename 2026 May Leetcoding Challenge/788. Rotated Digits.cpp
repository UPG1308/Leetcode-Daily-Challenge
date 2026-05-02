class Solution {
public:

    bool is_valid_number(int num){
        int cnt = 0;
        while(num){
            int ld = num % 10;
            if(ld == 3 || ld == 4 || ld == 7) return false;
            if(ld == 2 || ld == 5 || ld == 6 || ld == 9) cnt++;
            num /= 10;
        }
        return cnt > 0;
    }

    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 1; i <= n; ++i){
            count += is_valid_number(i);
        }
        return count;
    }
};
