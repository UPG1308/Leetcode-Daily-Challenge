class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        for(int i = 0; i < n; ++i){
            if(!st.empty() && arr[i] < arr[st.top()]){
                int top = st.top();
                st.pop();
                while(!st.empty() and arr[i] < arr[st.top()]) st.pop();
                st.push(top);
            }
            else st.push(i);
        }
        return st.size();
    }
};
