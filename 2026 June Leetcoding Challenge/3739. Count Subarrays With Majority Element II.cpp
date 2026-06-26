class Solution {
public:
    struct Fenwick {
    vector<int> bit;
    int n;
    Fenwick(int n): n(n), bit(n+1, 0) {}
    void add(int i, int val) {
        for (++i; i <= n; i += i & -i)
            bit[i] += val;
    }
    int sum(int i) {
        int s = 0;
        for (++i; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
};

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> prefix(n+1);
        for (int i = 0; i < n; ++i) {
            prefix[i+1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        // Coordinate compression
        vector<long long> vals = prefix;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        
        auto getIndex = [&](long long x) {
            return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
        };

        Fenwick bit(vals.size());
        long long ans = 0;
        for (long long x : prefix) {
            int idx = getIndex(x);
            ans += bit.sum(idx - 1);  // count previous prefix[j] < prefix[i]
            // cout <<  bit.sum(idx - 1) << " ";

            bit.add(idx, 1);
        }
        for(int i = 0; i < vals.size(); ++i){
            if(i == 0) cout << bit.sum(i) << " ";
            else cout << (bit.sum(i) - bit.sum(i - 1)) << " ";
        }
        return ans;
    }
};
