class Solution {
    public int pivotInteger(int n) {
        int sum = n * (n + 1)/2, left = 0;
        for(int i = 0; i <= n; i++){
            if((i * (i + 1)/2) == (sum + i - i * (i + 1)/2)) return i;
        }
        return -1;
    }
}
