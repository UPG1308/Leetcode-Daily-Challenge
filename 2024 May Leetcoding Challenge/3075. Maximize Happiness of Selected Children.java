class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        int n = happiness.length;
        Arrays.sort(happiness);
        long count = 0, cnt = 0;
        for(int i = n - 1; i >= 0 && k > 0; i--){
            k--;
            
            if(happiness[i] - cnt > 0)
                count += happiness[i] - cnt;
            cnt++;
        }
        return count;
    }
}
