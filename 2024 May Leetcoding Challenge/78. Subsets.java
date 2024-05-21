class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(0, nums, result, new ArrayList<>());
        return result;
    }
    public void backtrack(int start, int[] nums, List<List<Integer>> result, List<Integer> sublist){
        if(start == nums.length){
            result.add(new ArrayList<>(sublist));
            return;
        }
        int i = start;
        // for(int i = start; i < nums.length; i++){
            int num = nums[i];
            sublist.add(num);
            backtrack(i + 1,nums, result, sublist);
            sublist.remove(sublist.size() - 1);
            backtrack(i + 1, nums, result, sublist);
        // }
    }
}
