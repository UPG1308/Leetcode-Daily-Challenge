class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), i = 0, j = 0, ans = 0;
        for(; j < m && i < n; ++j){
            while(i < n && nums1[i] > nums2[j]) i++;
            if(i < n && nums1[i] <= nums2[j]) ans = max(ans, j - i);
        }
        return ans;
    }
};
