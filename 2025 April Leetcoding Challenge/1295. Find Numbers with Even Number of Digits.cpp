class Solution {
public:
    int countDigit(int n){
        int count = 0;
        while(n){
            n /= 10;
            count++;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int i: nums) ans += countDigit(i) % 2 == 0;
        return ans;
    }
};
