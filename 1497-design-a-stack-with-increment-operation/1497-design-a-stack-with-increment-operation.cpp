class CustomStack {
public:
    int count;
    vector<int> st;
    int n;
    
    CustomStack(int maxSize) {
        count = 0;
        n = maxSize;
        st.resize(n); 
    }
    
    void push(int x) {
        if(count == n) return; 
        st[count] = x; 
        count++;  
    }
    
    int pop() {
        if(count <= 0) return -1;  
        count--;  
        return st[count]; 
    }
    
    void increment(int k, int val) {
        int l = min(k, count); 
        for(int i=0;i<l;i++) {
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
