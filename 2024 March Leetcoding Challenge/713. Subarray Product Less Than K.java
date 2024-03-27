class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if(k <= 1) return 0;
        int product = 1, count = 0, begin = 0;
        for(int end = 0; end < nums.length; end++){
            product *= nums[end];
            while(product >= k){
                product /= nums[begin++];
            }
            count += end - begin + 1;
        }
        return count;
    }
}
