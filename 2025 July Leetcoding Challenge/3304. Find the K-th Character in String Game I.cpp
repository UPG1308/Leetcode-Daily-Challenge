class Solution {
public:
    char kthCharacter(int k) {
        if(k <= 1) return 'a';
        int n = __lg(k);
        return char((kthCharacter(k & ~(1 << n)) - 'a' + 1) % 26 + 'a');
    }
};
