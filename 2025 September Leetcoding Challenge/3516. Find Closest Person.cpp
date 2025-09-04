class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xz = abs(x - z), yz = abs(y - z);
        if(xz == yz) return 0;
        else if(xz < yz) return 1;
        return 2;
    }
};
