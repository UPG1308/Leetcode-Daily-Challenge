class Solution {
    public int minOperations(int[] nums, int k) {
        
        int xor = 0;
        for(int i: nums) xor ^= i;
        return Integer.bitCount(xor ^ k);
    }
}
