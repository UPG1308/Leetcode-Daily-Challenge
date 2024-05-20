class Solution {
    public int subsetXORSum(int[] nums) {
        int n = nums.length, or = 0;
        for(int num: nums) or |= num;
        return or * (int)Math.pow(2, n - 1);
    }
}
