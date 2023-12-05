class Solution {
    public int numberOfMatches(int n) {
        int odd = 0, count = 0;
        while(n > 1){
            if(n % 2 == 1){
                odd = 1;
                n = n - 1;
            }
            n = n / 2;
            count += n;
            n = n + odd;
            odd = 0;
        }
        return count;
        // int count = 0;
        // while(n > 1){
        //     count += (int) n / 2;
        //     n =(int) Math.ceil((double)n/2);
        // }
        // return count;
    }
}
