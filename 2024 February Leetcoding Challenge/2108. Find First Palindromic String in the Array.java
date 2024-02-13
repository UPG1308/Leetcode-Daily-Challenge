class Solution {
    public String firstPalindrome(String[] words) {
        for(String s: words){
            if(isPalindrome(s)) return s;
        }
        return "";
    }
    public boolean isPalindrome(String s){
        int left = -1, right = s.length();
        while(++left <= --right){
            if(s.charAt(left) != s.charAt(right)) return false;
        }
        return true;
    }
}
