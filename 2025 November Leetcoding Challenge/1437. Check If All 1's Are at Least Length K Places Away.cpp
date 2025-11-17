class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt = k;
        for(int i: nums){
            if(i == 0) cnt++;
            else {
                if(cnt < k) return false;
                cnt = 0;
            }
        }

        return true;
    }
};
