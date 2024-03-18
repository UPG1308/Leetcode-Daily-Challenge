class Solution {
    public int findMinArrowShots(int[][] points) {
        int n = points.length; 
        if(n == 0) return 0;

        Arrays.sort(points, (a,b) -> Integer.compare(a[0] , b[0]));
        int count = 1, endPoint = points[0][1];
        for(int i = 1; i < n; i++){
            if(points[i][0] > endPoint){
                count++;
                endPoint = points[i][1];
            }
            else endPoint = Math.min(endPoint, points[i][1]);
        }
        return count;
    }
}
