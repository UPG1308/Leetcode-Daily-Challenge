class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<pair<int, int>> a;
        int n = arr.size(), sum = 0;
        for(int begin = 0, end = 0; end < n; ++end){
            sum += arr[end];
            while(sum > target){
                sum -= arr[begin++];
            }
            if(sum == target) a.push_back(make_pair(begin, end));
        }

        int ans = 1e9;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0, j = 0; i < a.size(); ++i){
            auto [b, e] = a[i];
            while(a[j].second < b) pq.push(a[j].second - a[j].first + 1), j++;
            if(!pq.empty()) ans = min(ans, e - b + 1 + pq.top());
        }
        return ans == 1e9? -1: ans;
    }
};
