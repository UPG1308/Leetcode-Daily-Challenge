class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        customers = "#" + customers;
        vector<int> pref(n + 1), suff(n + 2);

        for(int i = 1; i <= n; ++i){
            pref[i] = pref[i - 1] + (customers[i] == 'N');
        }
        for(int i = n; i >= 1; --i){
            suff[i] = suff[i + 1] + (customers[i] == 'Y');
        }
        int penalty = n, ans = n;
        for(int i = 1; i <= n + 1; ++i){
            if(pref[i - 1] + suff[i] < penalty){
                penalty = pref[i - 1] + suff[i];
                ans = i - 1;
            }
        }
        return ans;
    }
};
