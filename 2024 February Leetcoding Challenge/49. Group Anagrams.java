class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> hm = new HashMap<>();
        for(String s: strs){
            char[] seq = s.toCharArray();
            Arrays.sort(seq);
            String sortedString = new String(seq);
            hm.computeIfAbsent(sortedString, (x) -> new LinkedList<String>()).add(s);
        }
        List<List<String>> ans = new LinkedList<>();
        for(List<String> s: hm.values()){
            ans.add(s);
        }
        return ans;
    }
}
