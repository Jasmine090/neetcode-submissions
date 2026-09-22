class MinStack {
    stack<pair<int, int>> s;
    int cur_min = INT_MAX;
public:
    MinStack() {
        cur_min = INT_MAX;
    }
    
    void push(int val) {
        s.push({val, cur_min});
        cur_min = min(cur_min, val);
    }
    
    void pop() {
        cur_min = s.top().second;
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return cur_min;
    }
};
