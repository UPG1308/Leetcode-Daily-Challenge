class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int n = deck.length;
        int ans[] = new int[n];
        int i = 0, j = 0, k = 0;
        Arrays.sort(deck);
        for(; j < n; i++){
            if(ans[i%n] == 0) k++;
            if(k % 2 == 1){
                ans[i % n] = deck[j];
                j++;
                k = -1;
            }
        }
        return ans;
    }
}
