#define ll long long
class Solution {
public:
    ll digitSum(ll num){
        ll sum = 0l;
        while(num > 0){        
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        ll sum = 0;
        for(char c: s){
            sum += digitSum(c - 'a' + 1);
        }
        while(k-- > 1){
            sum = digitSum(sum);
        }
        return sum;
    }
};
