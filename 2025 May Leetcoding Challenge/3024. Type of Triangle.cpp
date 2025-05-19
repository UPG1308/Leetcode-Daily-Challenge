class Solution {
public:
    string triangleType(vector<int>& nums) {
        int equal = 0;
        sort(nums.begin(), nums.end());
        if(nums[0] + nums[1] <= nums[2]) return "none";
        if(nums[0] == nums[1]) equal++;
        if(nums[1] == nums[2]) equal++;
        if(nums[0] == nums[2]) equal++;


        if(equal == 0) return "scalene";
        else if(equal == 1) return "isosceles";
        else return "equilateral";
    }
};
