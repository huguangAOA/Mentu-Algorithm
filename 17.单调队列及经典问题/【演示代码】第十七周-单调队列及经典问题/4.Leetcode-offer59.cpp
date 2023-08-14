class MaxQueue {
public:
    deque<int> q, mq;
    MaxQueue() {}
    
    int max_value() {
        if (mq.size() == 0) return -1;
        return mq.front();
    }
    
    void push_back(int value) {
        q.push_back(value);
        while (mq.size() && value > mq.back()) mq.pop_back();
        mq.push_back(value);
        return ;
    }
    
    int pop_front() {
        if (q.size() == 0) return -1;
        if (q.front() == mq.front()) mq.pop_front();
        int ret = q.front();
        q.pop_front();
        return ret;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */