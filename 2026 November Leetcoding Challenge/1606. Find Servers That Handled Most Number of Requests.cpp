class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for(int i = 0; i < k; ++i) available.insert(i);
        int n = arrival.size();

        vector<int> count(k);
        using T = pair<long long, int>;
        priority_queue<T, vector<T>, greater<T>> busy;

        for(int i = 0; i < n; ++i){
            while(!busy.empty() && busy.top().first <= arrival[i]){
                available.insert(busy.top().second);
                busy.pop();
            }

            if(available.empty()) continue;
            int index = i % k;
            auto it = available.lower_bound(index);
            if(it == available.end()) it = available.begin();
            int server = *it;
            count[server]++;
            available.erase(it);
            busy.push(make_pair(arrival[i] + load[i], server));
        }

        int cnt = *max_element(count.begin(), count.end());
        vector<int> ans;
        for(int i = 0; i < k; ++i){
            if(cnt == count[i]) ans.push_back(i);
        }
        return ans;
    }
};
