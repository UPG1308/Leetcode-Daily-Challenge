class Solution {
    public int compareVersion(String version1, String version2) {
        int n = version1.length(), m = version2.length();
        int i = 0, j = 0, val1 = 0, val2 = 0;
        StringBuilder sb1 = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();
        while(i < n && j < m){            
            while(i < n && version1.charAt(i) != '.')sb1.append(version1.charAt(i++));
            while(j < m && version2.charAt(j) != '.')sb2.append(version2.charAt(j++));
            val1 = Integer.valueOf(sb1.toString());
            val2 = Integer.valueOf(sb2.toString());
            if(val1 < val2) return -1;
            else if(val1 > val2) return 1; 
            i++; j++;
            if(i < n) sb1.setLength(0);
            if(j < m) sb2.setLength(0);
        }val1 = 0; val2 = 0;
        while(i < n){
            while(i < n && version1.charAt(i) != '.') sb1.append(version1.charAt(i++));
            i++;
            val1 = Integer.valueOf(sb1.toString());
            if(val1 < val2) return -1;
            else if(val2 < val1) return 1;
            if(i < n) sb1.setLength(0);
        }
        // val1 = 0; val2 = 0;
        while(j < m){
            while(j < m && version2.charAt(j) != '.') sb2.append(version2.charAt(j++));
            j++;
            val2 = Integer.valueOf(sb2.toString());
            if(val1 < val2) return -1;
            else if(val2 < val1) return 1;
            if(j < m) sb2.setLength(0);
        }
        return 0;
    }
}
