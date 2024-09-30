class CustomStack {
public:
    vector<int> st;
    int ptr = -1, size;
    CustomStack(int maxSize) {
        st.resize(maxSize);
        size = maxSize;
    }
    
    void push(int x) {
        if(ptr == size - 1) return;
        st[++ptr] = x;
    }
    
    int pop() {
        if(ptr == -1) return ptr;
        int top = st[ptr--];
        return top;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k && i <= ptr; i++){
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
