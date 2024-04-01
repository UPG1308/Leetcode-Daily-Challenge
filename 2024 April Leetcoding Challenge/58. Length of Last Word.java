class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length(), len = 0;
        boolean wordFound = false;
        for(int i = n - 1; i >= 0; i--){
            if(s.charAt(i) != ' '){
                len++;
                wordFound = true;
            }
            if(s.charAt(i) == ' ' && wordFound) break;
        }
        return len;
    }
}
