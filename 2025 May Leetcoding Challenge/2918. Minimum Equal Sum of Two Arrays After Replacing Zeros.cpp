class Solution {
public:
    #define ll long long
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        ll zeros1 = count(nums1.begin(), nums1.end(), 0);
        ll zeros2 = count(nums2.begin(), nums2.end(), 0);

        ll sum1 = accumulate(nums1.begin(), nums1.end(), 0LL) + zeros1;
        ll sum2 = accumulate(nums2.begin(), nums2.end(), 0LL) + zeros2;

        if((zeros1 == 0 && sum1 < sum2) || (zeros2 == 0 && sum1 > sum2)) return -1;
        return max(sum1, sum2);
    }
};
