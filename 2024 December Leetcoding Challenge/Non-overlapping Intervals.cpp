 bool compare(const std::vector<int>& a, const std::vector<int>& b) {
    return a[1] < b[1]; // Sort based on the first element of each subvector
}
class Solution {
    
  public:
    int minRemoval(vector<vector<int>> &arr) {
         
     
      sort(arr.begin(), arr.end(), compare);
       
        int maxi = arr[0][1];
     
   
       int ans = 0 ;
        for(int i = 1 ; i < arr.size();i++){
            int f = arr[i][0];
            int s = arr[i][1];
         
             
            if(maxi >  f) ans++;
            else {
                maxi = s;
            }
        }
        
        return ans;
    }
};
