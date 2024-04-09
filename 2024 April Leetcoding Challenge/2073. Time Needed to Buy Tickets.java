class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int n = tickets.length;
        int time = tickets[k];

        for(int i = 0; i < k; i++){
            time += Math.min(tickets[i], tickets[k]);
        }
        for(int i = k + 1; i < n; i++){
            time += Math.min(tickets[i], tickets[k] - 1);
        }
        return time;
    }
}
