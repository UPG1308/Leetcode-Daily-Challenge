class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mp;
        for(int i: nums) mp[i]++;
        int lastDig = -1, lastCount = 0, count = 0;
        
        for(auto [num, val]: mp){
            if(lastDig + 1 == num){
                count = max(count, lastCount + val);
            }
            lastDig = num, lastCount = val;
        }
        return count;
    }
};
