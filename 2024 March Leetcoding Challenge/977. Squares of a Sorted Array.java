class Solution {
    public int[] sortedSquares(int[] nums) {
        ArrayList<Integer> positive = new ArrayList<>();
        ArrayList<Integer> negative = new ArrayList<>();
        for(int i = 0; i < nums.length; i++){
            if(nums[i] < 0) negative.add(nums[i] * nums[i]);
            else positive.add(nums[i] * nums[i]);
        }
        Collections.reverse(negative);
        int i = 0, j = 0, k = 0, n = positive.size(), m = negative.size();
        while(i < n && j < m){
            if(positive.get(i) < negative.get(j)) nums[k++] = positive.get(i++);
            else nums[k++] = negative.get(j++);
        }
        while(i < n) nums[k++] = positive.get(i++);
        while(j < m) nums[k++] = negative.get(j++);
        return nums;
    }
}
