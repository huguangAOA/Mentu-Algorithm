class SummaryRanges {
public:
    typedef pair<int, int> PII;
    set<PII> s;
    unordered_set<int> uniq;
    SummaryRanges() {}
    
    PII mergePre(PII d) {
        auto pre = s.find(d);
        auto now = (pre--);
        if (pre == s.end() || pre->second + 1 != now->first) return d;
        auto pre_d = *pre;
        s.erase(pre);
        s.erase(s.find(d));
        d.first = pre_d.first;
        s.insert(d);
        return d;
    }

    PII mergeNext(PII d) {
        auto next = s.find(d);
        auto now = (next++);
        if (next == s.end() || next->first - 1 != now->second) return d;
        auto next_d = *next;
        s.erase(next);
        s.erase(s.find(d));
        d.second = next_d.second;
        s.insert(d);
        return d;
    }

    void addNum(int val) {
        if (uniq.find(val) != uniq.end()) return ;
        uniq.insert(val);
        PII d(val, val);
        s.insert(d);
        d = mergePre(d);
        d = mergeNext(d);
        return ;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        vector<int> range(2);
        for (auto x : s) {
            range[0] = x.first;
            range[1] = x.second;
            ret.push_back(range);
        }
        return ret;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */