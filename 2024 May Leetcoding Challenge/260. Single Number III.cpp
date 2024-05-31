class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int number = 0;
        for( int i = 0; i < nums.size(); i++ ){
            number ^= nums[i];
        }
        int setBit = 1;
        while( true ){
            if( number & ( setBit ) ){
                break;
            }
            setBit <<= 1;
        }
        int firstAns = 0;
        for( int i = 0; i < nums.size(); i++ ){
            if( nums[i]&setBit ){
                firstAns ^= nums[i];
            }
        }
        int secondAns = firstAns^number;
        return {firstAns,secondAns}; 
    }
};
