class Solution {
    public String destCity(List<List<String>> paths) {
        HashSet<String> source = new HashSet<>();
        for(List<String> path: paths)source.add(path.get(0));

        for(List<String> path:paths){
            if(!source.contains(path.get(1))) return path.get(1);
        }
        return "";
    }
}
