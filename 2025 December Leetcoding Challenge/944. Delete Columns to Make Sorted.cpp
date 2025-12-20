class Solution {
public:

    int countNotSortedColumns(vector<string>& s){
        int count = 0;
        for(int j = 0; j < int(s[0].size()); ++j){
            for(int i = 1; i < s.size(); ++i) {
                if(s[i][j] < s[i - 1][j]) {
                    count++;
                    break;
                }
            }
        }

        return count;
    }

    int minDeletionSize(vector<string>& strs) {
        int ans = strs[0].size();
        ans = min(ans, countNotSortedColumns(strs));

        return ans;
    }
};
