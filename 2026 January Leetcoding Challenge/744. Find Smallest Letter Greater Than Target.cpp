class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto ub = upper_bound(letters.begin(), letters.end(), target);
        return ub == letters.end()? letters[0]: *ub;
    }
};
