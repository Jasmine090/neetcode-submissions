class MinStack {
    vector<pair<int, int>> s;
    int cur_min = INT_MAX;
public:
    MinStack() {
        cur_min = INT_MAX;
    }
    
    void push(int val) {
        s.push_back({val, cur_min});
        cur_min = min(cur_min, val);
    }
    
    void pop() {
        cur_min = s.back().second;
        s.pop_back();
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return cur_min;
    }
};
