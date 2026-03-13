class Solution {
public:
    using ll = long long;
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();

        auto evaluate = [&](ll wtime, ll t){
            ll l = -1, r = mountainHeight + 1;
            while(r - l > 1){
                ll m = l + (r - l)/2;
                if(wtime * m * (m + 1)/2 <= t) l = m;
                else r = m;
            }
            return l;
        };

        auto check = [&](ll t){
            ll amount = 0;
            for(ll i: workerTimes){
                amount += evaluate(i, t);
            }
            return amount >= mountainHeight;
        };

        ll l = 0, r = 1e18 + 1;
        while(r - l > 1){
            ll m = l + (r - l)/2;
            if(check(m)) r = m;
            else l = m;
        }

        return r;
    }
};
