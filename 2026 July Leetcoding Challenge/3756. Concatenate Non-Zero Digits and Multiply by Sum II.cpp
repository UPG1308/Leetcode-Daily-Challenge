class Solution {
public:
    long long MOD = 1e9 + 7;

    long long binpow(long long a, long long b){
        long long ans = 1;
        while(b){
            if(b & 1) ans *= a;
            a = (a * a) % MOD;
            b = b >> 1;
            ans %= MOD;
        }
        return ans;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> prefS(n + 2), prefSum(n + 2), prefCnt(n + 2);

        for(int i = 0; i < n; ++i){
            if(s[i] == '0'){
                prefS[i + 1] = prefS[i];
                prefSum[i + 1] = prefSum[i];
                prefCnt[i + 1] = prefCnt[i];
            }
            else {
                prefS[i + 1] = (prefS[i] * 10 + (s[i] - '0')) % MOD;
                prefSum[i + 1] = (prefSum[i] + (s[i] - '0')) % MOD;
                prefCnt[i + 1] = prefCnt[i] + 1;
            }
        }

        vector<int> ans;
        for(auto q: queries){
            int l = q[0], r = q[1];
            int tenCnt = prefCnt[r + 1] - prefCnt[l];
            long long val = (prefS[r + 1] - (prefS[l] * binpow(10, tenCnt) % MOD) + MOD) % MOD;
            long long sum = (prefSum[r + 1] - prefSum[l] + MOD) % MOD;
            ans.push_back((val * sum) % MOD);
        }
        return ans;
    }
};
