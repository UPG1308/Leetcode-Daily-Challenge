class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p = 0, q = n - 1;
        while(p + 1 < n && nums[p] < nums[p + 1]) p++;
        while(q - 1 > p && nums[q - 1] < nums[q]) q--;

        for(int i = p; i < q; ++i){
            if(nums[i + 1] >= nums[i]) return false;
        }

        return p != 0 && q != (n - 1);
    }
};
