class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> occupied(n);

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(fruits[i] <= baskets[j] && !occupied[j]){
                    occupied[j] = true;
                    break;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; ++i) count += !occupied[i];
        return count;
    }
};
