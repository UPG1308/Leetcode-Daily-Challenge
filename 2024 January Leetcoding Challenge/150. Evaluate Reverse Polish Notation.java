class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        for(String c: tokens){
            if(Character.isDigit(c.charAt(c.length() - 1))) st.push(Integer.valueOf(c));
            else{
                int b = st.pop();
                int a = st.pop();
                int res = 0;
                if(c.equals("-")) res = a - b;
                else if(c.equals("+")) res = a + b;
                else if(c.equals("*")) res = a * b;
                else res = a / b;
                st.push(res);
            }
        }
        return st.pop();
    }
}
