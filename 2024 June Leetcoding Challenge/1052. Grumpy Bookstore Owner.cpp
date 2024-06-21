class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();

        int customer = 0, val = 0;
        for(int i = 0; i < n; i++) customer += (grumpy[i] == 0)?customers[i]:0;
        for(int i = 0; i < minutes; i++) val += (grumpy[i] == 1)?customers[i]:0;
        int mx = val;
        for(int i = minutes; i < n; i++){
            val -= (grumpy[i - minutes] == 1)?customers[i - minutes]:0;
            val += (grumpy[i] == 1)?customers[i]:0;
            mx = max(val, mx);
        }
        return mx + customer;
    }
};
