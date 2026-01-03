class Solution {
public:
    static const int MOD = 1e9 + 7;
    int numOfWays(int n) {
        long long dpA = 6; // ABC type
        long long dpB = 6; // ABA type

        for (int i = 2; i <= n; i++) {
            long long newA = (2 * dpA + 2 * dpB) % MOD;
            long long newB = (2 * dpA + 3 * dpB) % MOD;
            dpA = newA;
            dpB = newB;
        }

        return (dpA + dpB) % MOD;
    }
};
