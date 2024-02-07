class Solution {
    public String frequencySort(String s) {
        int map[] = new int[128];
        for(char c: s.toCharArray()) map[c - '0']++;

        PriorityQueue<Character> heap = new PriorityQueue<>((a, b) -> map[b - '0'] - map[a - '0']);
        for(int i = 0 ; i < 128; i++) {
            if(map[i] != 0) heap.offer((char) (i + '0'));
        }
        StringBuilder str = new StringBuilder();
        while(!heap.isEmpty()){
            char c = heap.poll();
            while(map[c - '0']-- > 0) str.append(c);
        }
        return str.toString();
    }
}
