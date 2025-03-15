class Solution {
public:
    int isValid(vector<int>& nums, int requiredHouses, int capability){
        int totalHouses = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] <= capability){
                totalHouses++;
                ++i;
            }
        }
        return totalHouses >= requiredHouses;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = -1, r = *max_element(nums.begin(), nums.end()) + 1;

        while(r - l > 1){
            int m = l + (r - l)/2;
            if(isValid(nums, k, m)) r = m;
            else l = m;
        }
        return r;
    }
};
