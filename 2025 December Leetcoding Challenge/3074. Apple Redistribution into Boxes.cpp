class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples = accumulate(apple.begin(), apple.end(), 0);
        int m = capacity.size();
        sort(capacity.rbegin(), capacity.rend());

        int capacties = 0, i = 0;
        while(i < m && capacties + capacity[i] < apples) capacties += capacity[i++];
        return i + 1;
    }
};
