class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        queue<int> q_tmp;
        // while(q.size()){
        //     q_tmp.push(q.front());
        //     q.pop();
        // }
        q.push(x);
        // while(q_tmp.size()){
        //     q.push(q_tmp.front());
        //     q_tmp.pop();
        // }
    }
    
    int pop() {
        queue<int> q_tmp;
        int re = 0;
        while(q.size()){
            if(q.size()==1) re = q.front();
            else q_tmp.push(q.front());
            q.pop();
        }
        while(q_tmp.size()){
            q.push(q_tmp.front());
            q_tmp.pop();
        }
        return re;
    }
    
    int top() {
        queue<int> q_tmp;
        int re = 0;
        while(q.size()){
            if(q.size()==1) re = q.front();
            q_tmp.push(q.front());
            q.pop();
        }
        while(q_tmp.size()){
            q.push(q_tmp.front());
            q_tmp.pop();
        }
        
        return re;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */