class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i <= n; ++i){
            while(!st.empty() && (i == n || arr[i] < arr[st.top()])){
                int top = st.top(); st.pop();
                int left = st.empty()? -1: st.top();
                ans += arr[top] * (top - left) * (i - top);
            }
            st.push(i);
        }
        return ans;
    }
};
