class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        int n = arr.size(), ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i){
            if(mp.count(arr[i])) ans = max(ans, i - mp[arr[i]]);
            else mp[arr[i]] = i;
        }
        return ans;
    }
};
