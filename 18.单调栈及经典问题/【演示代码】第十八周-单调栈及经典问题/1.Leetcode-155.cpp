class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s, min_s;
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if (min_s.size() == 0 || val <= min_s.top()) {
            min_s.push(val);
        }
        return ;
    }
    
    void pop() {
        if (s.top() == min_s.top()) min_s.pop();
        s.pop();
        return ;
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
