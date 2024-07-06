class Solution {
public:
    int passThePillow(int n, int time) {
        int direction = time / (n - 1);
        if(direction & 1) return n - time % (n - 1);
        return time % (n - 1) + 1;
    }
};
