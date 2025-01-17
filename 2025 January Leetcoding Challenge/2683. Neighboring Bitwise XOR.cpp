class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xo = 0;
        for(int num: derived) xo ^= num;
        return xo == 0;
    }
};
