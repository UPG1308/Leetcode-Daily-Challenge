template <typename T> class SparseTable {
  private:
	int n, log2dist;
	vector<vector<T>> mini, maxi;

  public:
	SparseTable(const vector<T> &v) {
		n = (int)v.size();
		log2dist = 1 + (int)log2(n);
		mini.resize(log2dist);
        maxi.resize(log2dist);
		mini[0] = maxi[0] = v;
		for (int i = 1; i < log2dist; i++) {
			mini[i].resize(n - (1 << i) + 1);
            maxi[i].resize(n - (1 << i) + 1);
			for (int j = 0; j + (1 << i) <= n; j++) {
				mini[i][j] = min(mini[i - 1][j], mini[i - 1][j + (1 << (i - 1))]);
                maxi[i][j] = max(maxi[i - 1][j], maxi[i - 1][j + (1 << (i - 1))]);
			}
		}
	}

	/** @return minimum on the range [l, r] */
	T min_query(int l, int r) {
		int i = (int)log2(r - l + 1);
		return min(mini[i][l], mini[i][r - (1 << i) + 1]);
	}

    /** @return maximum on the range [l, r] */
	T max_query(int l, int r) {
		int i = (int)log2(r - l + 1);
		return max(maxi[i][l], maxi[i][r - (1 << i) + 1]);
	}
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<array<long long, 3>> pq;
        SparseTable<int> sp(nums);

        for(int i = 0; i < n; ++i){
            long long mx = sp.max_query(i, n - 1);
            long long mn = sp.min_query(i, n - 1);
            pq.push({mx - mn, i, n - 1});
        }

        long long ans = 0;
        while(k-- && !pq.empty()){
            auto [v, l, r] = pq.top(); pq.pop();
            ans += v;
            if(l < r){
                long long mx = sp.max_query(l, r - 1);
                long long mn = sp.min_query(l, r - 1);
                pq.push({mx - mn, l, r - 1});
            }
        }

        return ans;
    }
};
