class Solution {
    public long largestPerimeter(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        long perimeter = nums[0] + nums[1], maxPerimeter = Integer.MIN_VALUE;
        for(int i = 2; i < n; i++){
            if(nums[i] < perimeter) maxPerimeter = Math.max(maxPerimeter, nums[i] + perimeter);
            perimeter += nums[i];
        }
        if(maxPerimeter == Integer.MIN_VALUE) return -1;
        return maxPerimeter;
    }
}
