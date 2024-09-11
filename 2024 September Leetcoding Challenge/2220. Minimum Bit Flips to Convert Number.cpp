class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __popcount(start ^ goal);
    }
};
