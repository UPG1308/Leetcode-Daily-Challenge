class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int even = 1, odd = 1;
        for(int i = 1; i < n; ++i){
            even &= (nums1[i] % 2 == nums1[i - 1] % 2);
            odd &= (nums1[i] % 2 == nums1[i - 1] % 2);
        }
        if (even || odd) return true;

        even = odd = 1e9;
        for(int i: nums1){
            if(i & 1) odd = min(odd, i);
            else even = min(even, i);
        }

        return even >= odd;
    }
};
