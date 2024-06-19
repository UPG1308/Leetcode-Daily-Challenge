class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long) m * k > n) return -1;
        int low = 0, high = 1e4;
        for(int i: bloomDay) 
        low = min(low, i), high = max(high, i);
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, k, bloomDay, m)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
    bool isPossible(int days, int k, vector<int>& bloomDay, int bouquets){
        int totalBouquets = 0, count = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= days){
                count++;
            }
            else totalBouquets += count / k, count = 0;
        }
        totalBouquets += count / k, count = 0;
        return totalBouquets >= bouquets;
    }
};
