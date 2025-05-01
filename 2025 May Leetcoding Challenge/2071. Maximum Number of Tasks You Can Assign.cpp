class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                      int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto check = [&](int mid) -> bool {
            int p = pills;
            // Ordered set of workers
            multiset<int> ws;
            for (int i = m - mid; i < m; ++i) {
                ws.insert(workers[i]);
            }
            // Enumerate each task from largest to smallest
            for (int i = mid - 1; i >= 0; --i) {
                // If the largest element in the ordered set is greater than or
                // equal to tasks[i]
                if (auto it = prev(ws.end()); *it >= tasks[i]) {
                    ws.erase(it);
                } else {
                    if (!p) {
                        return false;
                    }
                    auto rep = ws.lower_bound(tasks[i] - strength);
                    if (rep == ws.end()) {
                        return false;
                    }
                    --p;
                    ws.erase(rep);
                }
            }
            return true;
        };
        
        int left = 0, right = min(m, n) + 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (check(mid)) left = mid;
            else right = mid;
        }
        return left;
    }
};
