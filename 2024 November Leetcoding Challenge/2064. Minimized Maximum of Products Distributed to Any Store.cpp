class Solution {
public:
    bool isPossible(int maxval, vector<int>& quantities, int m, int n){
        int stores = 0;
        for(int quant: quantities) stores += (quant + maxval - 1)/maxval;
        return stores <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int low = 1, high = *max_element(quantities.begin(), quantities.end()) , ans = m;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, quantities, m, n)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
