class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1), ans(n);

        for(int i = 0; i < n; ++i){
            int cnt = 0;
            cnt += (++freq[A[i]] == 2? 1: 0);
            cnt += (++freq[B[i]] == 2? 1: 0);
            ans[i] = cnt;
            if(i) ans[i] += ans[i - 1];
        }
        return ans;
    }
};
