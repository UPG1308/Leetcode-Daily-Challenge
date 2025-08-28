class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int j = n - 1; j > 0; --j){
            int left = 0, right = j;
            vector<int> arr;
            while(left < n && right < n){
                arr.push_back(grid[left][right]);
                left++, right++;
            }

            sort(arr.begin(), arr.end());

            left = 0, right = j;
            int k = 0;
            while(left < n && right < n){
                grid[left++][right++] = arr[k++];
            }
        }

        for(int i = 0; i < n; ++i){
            int left = i, right = 0;
            vector<int> arr;
            while(left < n && right < n){
                arr.push_back(grid[left][right]);
                left++, right++;
            }

            sort(arr.rbegin(), arr.rend());

            left = i, right = 0;
            int k = 0;
            while(left < n && right < n){
                grid[left++][right++] = arr[k++];
            }
        }
        return grid;
    }
};
