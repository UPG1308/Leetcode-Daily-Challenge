class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length , ans[] = new int[n];
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i < n; i++){
            while(!st.isEmpty() && temperatures[i] > temperatures[st.peek()]){
                    ans[st.peek()] = i - st.pop();
                }
            st.push(i);
        }
        return ans;
    }
}
