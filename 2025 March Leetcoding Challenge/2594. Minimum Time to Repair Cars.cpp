class Solution {
public:
    bool isValid(vector<int> &ranks, int cars, long long minutes){
        long long totalCars = 0;
        for(int rank: ranks){
            totalCars += sqrt(minutes/rank);
        }
        return totalCars >= cars;
    }
    long long repairCars(vector<int>& ranks, long long cars) {
        long long l = -1;
        long long r = (*max_element(ranks.begin(), ranks.end()) * cars * cars * 1LL) + 1;

        while(r - l > 1){
            long long m = l + (r - l)/2;
            if(isValid(ranks, cars, m)) r = m;
            else l = m;
        }
        return r;
    }
};
