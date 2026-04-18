class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n, val = 0;
        while(temp){
            int ld = temp % 10;
            val = val * 10 + ld;
            temp /= 10;
        }
        return abs(n - val);
    }
};
