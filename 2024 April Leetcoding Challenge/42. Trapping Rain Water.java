class Solution {
    public int trap(int[] height) {
        int n = height.length;
        Stack<Integer> st = new Stack<>();

        int count = 0;
        for(int i = 0; i < n; i++){
            if(!st.isEmpty() && height[i] > height[st.peek()]){
                int heig = Math.min(height[i], height[st.peek()]);
                int wid = i - st.peek() - 1;
                len += heig * wid;
            }

        }
    }
}
