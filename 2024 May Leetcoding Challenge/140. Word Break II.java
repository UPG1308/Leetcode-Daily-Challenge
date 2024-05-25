class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        HashSet<String> set = new HashSet<>(wordDict);
        List<String> ans = new ArrayList<>();
        helper(0, new StringBuilder(s), set, new StringBuilder(), ans);
        return ans;
    }
    public void helper(int start, StringBuilder s, HashSet<String> set, StringBuilder temp, List<String> ans){
        if(start == s.length()){
            ans.add(new String(temp));
        }
        for(int end = start; end < s.length(); end++){
            StringBuilder sub = s.substring(start, end + 1);
            if(set.contains(sub)){
                helper(end + 1, s, set, temp.concate(sub +" "), ans);
            }
        }
    }
}
