class Solution {
public:
    bool isValid(vector<int>& candies, long long childrens, long long candiesPerChildren){
        long long totalChildren = 0;
        if(candiesPerChildren == 0) return true;
        for(int candy: candies){
            totalChildren += candy / candiesPerChildren;
        }
        return totalChildren >= childrens;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int ans = 0;
        int mx = *max_element(candies.begin(), candies.end());
        int l = 0, r = mx + 1;
        while(r - l > 1){
            int m = l + (r - l) / 2;
            if(isValid(candies, k, m)) l = m;
            else r = m;
        }
        return l;
    }
};
