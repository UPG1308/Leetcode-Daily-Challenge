class Solution {
    public int findSpecialInteger(int[] arr) {
        int n = arr.length;
        int i = 0, k = 0, max = (double)1 / n > 0.25? arr[i]: -1;
        for(int j = 1; j < n; j++){
            if(arr[j] == arr[j - 1]) k++;
            else {
                i = j;
                k = j;
            }
            int occurance = j - i + 1;
            if((double)occurance / n > 0.25) max = arr[j];
        }
        return max;
    }
}
===============================================================================================
class Solution {
 public int findSpecialInteger(int[] arr) {
        int n = arr.length;
        HashMap<Integer, Integer> hm = new HashMap<>();
        for(int i : arr) hm.put(i, hm.getOrDefault(i, 0) + 1);

        for(int i: hm.keySet()){
            if((double)hm.get(i)/n > 0.25) return i;
        }
        return -1;
    }
  }
==============================================================================================
  class Solution {
    public int findSpecialInteger(int[] arr) {
        Map<Integer, Integer> counts = new HashMap();
        int target = arr.length / 4;
        for (int num : arr) {
            counts.put(num, counts.getOrDefault(num, 0) + 1);
            if (counts.get(num) > target) {
                return num;
            }
        }

        return -1;
    }
}

==================================================================================================

  class Solution {
    public int findSpecialInteger(int[] arr) {
        int size = arr.length / 4;
        for (int i = 0; i < arr.length - size; i++) {
            if (arr[i] == arr[i + size]) {
                return arr[i];
            }
        }
        
        return -1;
    }
}
=======================================BINARY SEARCH===========================================================
  class Solution {
    public int findSpecialInteger(int[] arr) {
        int n = arr.length;
        int[] candidates = {arr[n / 4], arr[n / 2], arr[3 * n / 4]};
        int target = n / 4;
        
        for (int candidate : candidates) {
            int left = lower_bound(arr, candidate);
            int right = upper_bound(arr, candidate) - 1;
            if (right - left + 1 > target) {
                return candidate;
            }
        }
        
        return -1;
    }
    
    public int upper_bound(int[] arr, int target) {
        int left = 0;
        int right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
    
    public int lower_bound(int[] arr, int target) {
        int left = 0;
        int right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
}
