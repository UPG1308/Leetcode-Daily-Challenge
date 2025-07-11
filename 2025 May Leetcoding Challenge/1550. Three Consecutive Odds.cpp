class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2) return false;
        for(int i = 1; i < n - 1; ++i){
            if((arr[i] & 1) && (arr[i - 1] & 1) && (arr[i + 1] & 1)) return true;
        }
        return false;
    }
};
