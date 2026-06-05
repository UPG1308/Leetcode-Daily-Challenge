#include <bits/stdc++.h>
using namespace std;

long long dp[20][11][11][2][2];
long long dp2[20][11][11][2][2];
string s;

pair<long long,long long> solveDP(int pos, int d2, int d1, bool tight, bool started) {
    if (pos == s.size()) return {started ? 1 : 0, 0};

    long long &c1 = dp[pos][d2+1][d1+1][tight][started];
    long long &c2 = dp2[pos][d2+1][d1+1][tight][started];
    if (c1 != -1) return {c1, c2};

    long long totalCnt = 0, totalWav = 0;
    int limit = tight ? (s[pos]-'0') : 9;

    for (int dig = 0; dig <= limit; dig++) {
        bool ntight = tight && (dig == limit);
        bool nstarted = started || (dig > 0);

        auto sub = solveDP(pos+1,
                nstarted ? d1 : -1,
                nstarted ? dig : -1,
                ntight,
                nstarted);

        long long cnt = sub.first, wav = sub.second;

        if (nstarted && d2 != -1 && d1 != -1) {
            if ((d2 < d1 && d1 > dig) || (d2 > d1 && d1 < dig)) {
                wav += cnt; // every number contributing adds 1
            }
        }

        totalCnt += cnt;
        totalWav += wav;
    }

    c1 = totalCnt;
    c2 = totalWav;
    return {totalCnt, totalWav};
}

long long calc(long long x) {
    if (x <= 0) return 0;
    s = to_string(x);
    memset(dp,-1,sizeof(dp));
    memset(dp2,-1,sizeof(dp2));
    return solveDP(0, -1, -1, true, false).second;
}

class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1-1);
    }
};
