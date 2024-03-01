class Solution {
    public String maximumOddBinaryNumber(String s) {
        int n = s.length();
        int one = 0, zero = 0;
        for(char c: s.toCharArray()){
            if(c == '0') zero++;
            else one++;
        }
        one--;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n - 1; i++){
            if(one-- > 0) sb.append('1');
            else sb.append('0');
        }
        return sb.append('1').toString();
    }
}
