class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> tmp;
        while(st.size()){
            tmp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(tmp.size()){
            st.push(tmp.top());
            tmp.pop();
        }
    }
    
    int pop() {
        int re = st.top();
        st.pop();
        return re;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */