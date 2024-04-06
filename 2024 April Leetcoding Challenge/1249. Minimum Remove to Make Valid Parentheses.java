class Solution {
    public String minRemoveToMakeValid(String s) {
        int n = s.length();
        StringBuilder sb = new StringBuilder();
        int open = 0, close = 0, currentOpenBrackets = 0, noOfClosingBracketsAvailableInFuture = 0;
        for(char c: s.toCharArray()){
            if(c == '(') open++;
            else if(c == ')') {close++; noOfClosingBracketsAvailableInFuture++;}
        }
        // System.out.println(close+" "+open);
        for(char c: s.toCharArray()){
            if(c != '(' && c != ')') sb.append(c);
            else if(c == '(' && noOfClosingBracketsAvailableInFuture > 0){
                sb.append(c); noOfClosingBracketsAvailableInFuture--;currentOpenBrackets++;
            }
            else if(c == ')' && currentOpenBrackets > 0){
                sb.append(c); currentOpenBrackets--; 
            }
            else if(c == ')') noOfClosingBracketsAvailableInFuture--;
        }
        return sb.toString();
    }
}
