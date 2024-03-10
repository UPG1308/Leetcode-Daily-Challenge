//Sorting and Two Pointer

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        // Sort both arrays
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        // Initialize two pointers
        int N = nums1.length;
        int M = nums2.length;
        int p1 = 0;
        int p2 = 0;
        
        // Create set that stores integers appearing in both arrays
        Set<Integer> intersection = new HashSet<>();

        // Iterate the pointers from left to right
        while (p1 < N && p2 < M) {
            // Add a value to the set if values at both pointers equal
            if (nums1[p1] == nums2[p2]) {
                intersection.add(nums1[p1]);
                p1++;
                p2++;
            }
            // Otherwise, increment the pointer of the smaller integer
            else if (nums1[p1] < nums2[p2]) {
                p1++;
            }
            else {
                p2++;
            }
        }

        // Convert intersection to an array
        int K = intersection.size();
        int[] result = new int[K];
        int curr = 0;
        for (int x: intersection) {
            result[curr++] = x;
        }

        //Return the result
        return result;
    }
}

//============================================= Built-in Set Intersection =====================================================

class Solution {
  public int[] intersection(int[] nums1, int[] nums2) {
    Set<Integer> set1 = new HashSet<>();
    for (Integer n : nums1) {
        set1.add(n);
    } 
    Set<Integer> set2 = new HashSet<>();
    for (Integer n : nums2) {
        set2.add(n);
    }
    set1.retainAll(set2);
    int[] output = new int[set1.size()];
    int idx = 0;
    for (int s : set1) {
        output[idx++] = s;
    }
    return output;
  }
}

//======================================================== Two Sets ==========================================================

class Solution {
  public int[] setIntersection(Set<Integer> set1, Set<Integer> set2) {
    int[] output = new int[set1.size()];
    int idx = 0;
    for (Integer s : set1) {
        if (set2.contains(s)){
            output[idx++] = s;
        } 
    }
    return Arrays.copyOf(output, idx);
  }
  public int[] intersection(int[] nums1, int[] nums2) {
    Set<Integer> set1 = new HashSet<>();
    for (Integer n : nums1) {
        set1.add(n);
    } 
    Set<Integer> set2 = new HashSet<>();
    for (Integer n : nums2) {
        set2.add(n);
    }
    if (set1.size() < set2.size()){
        return setIntersection(set1, set2);
    } else {
        return setIntersection(set2, set1);
    } 
  }
}

//============================================= One Dictionary ====================================================

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        
        // Initialize seen map and result list
        Map<Integer, Integer> seen = new HashMap<>();
        List<Integer> result = new ArrayList<>();

        // Mark values occurring in nums1
        for (int x : nums1) {
            seen.put(x, 1);
        }

        // Check if n is in dictionary and not in the result
        for (int x : nums2) {
            if (seen.containsKey(x) && seen.get(x) == 1) {
                result.add(x);
                seen.put(x, 0);
            }
        }

        // Convert to int array and result the result
        return result.stream().mapToInt(i->i).toArray();
        
    }
}
