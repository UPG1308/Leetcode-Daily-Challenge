class Solution {
public:
    int factors(int num){
        int sum = 0, div = 0;
        for(int i = 1; i * i <= num; ++i){
            if(num % i == 0){
                sum += i;
                if(i != num/i) sum += num/i, div++;
                div++;
            }
        }
        return div == 4? sum: 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        map<int, int> mp;

        for(int num: nums){
            if(!mp.count(num)) mp[num] = factors(num);
            sum += mp[num];
        }
        return sum;
    }
};
