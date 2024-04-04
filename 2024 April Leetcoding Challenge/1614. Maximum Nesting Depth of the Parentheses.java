class Solution {
    public int maxDepth(String s) {
        int n = s.length(), count = 0, max = 0;
        for(char c: s.toCharArray()){
            if(c == '(') max = Math.max(max, count++);
            else if(c == ')') max = Math.max(max, count--);
        }
        return max;
    }
}
