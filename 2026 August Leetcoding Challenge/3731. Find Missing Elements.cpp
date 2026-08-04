class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        set<int> st(nums.begin(), nums.end());
        vector<int> ans;

        for(int i = mn; i <= mx; ++i){
            if(st.count(i)) continue;
            ans.push_back(i);
        }
        return ans;
    }
};
