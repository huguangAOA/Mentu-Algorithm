class StockSpanner {
public:
    typedef pair<int, int> PII;
    int t;
    stack<PII> s;
    StockSpanner() {
        t = 0;
        s.push(PII(INT_MAX, t++));
    }
    
    int next(int price) {
        while (s.size() && price >= s.top().first) s.pop();
        int ret = t - s.top().second;
        s.push(PII(price, t++));
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */