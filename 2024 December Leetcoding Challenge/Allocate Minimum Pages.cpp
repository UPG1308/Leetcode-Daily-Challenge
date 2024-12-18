class Solution {
  public:
    
    bool isPossible(int mid, vector<int>& arr, int k, int n){
        int sum = 0, count = 1;
        for(int num: arr){
            if(sum + num > mid){
                count++;
                sum = num;
            }
            else sum += num;
        }
        return count <= k;
    }
  
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size(), ans = 0;
        if(n < k) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, arr, k, n)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
