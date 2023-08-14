class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {}
    unordered_map<string, map<int, string> > h;
    void set(string key, string value, int timestamp) {
        h[key][timestamp] = value;
        return ;
    }
    
    string get(string key, int timestamp) {
        if (h.find(key) == h.end()) return "";
        if (h[key].find(timestamp) != h[key].end()) return h[key][timestamp];
        h[key].insert(pair<int, string>(timestamp, ""));
        auto iter = h[key].find(timestamp);
        string ret = (--iter)->second;
        h[key].erase(h[key].find(timestamp));
        return ret;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */