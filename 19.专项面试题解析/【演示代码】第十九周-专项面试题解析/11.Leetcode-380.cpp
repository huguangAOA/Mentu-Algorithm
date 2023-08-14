class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> h;
    vector<int> arr;
    RandomizedSet() {
        srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (h.find(val) != h.end()) return false;
        h[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    void swap_item(int i, int j) {
        swap(arr[i], arr[j]);
        h[arr[i]] = i;
        h[arr[j]] = j;
        return ;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (h.find(val) == h.end()) return false;
        int n = h[val], m = arr.size() - 1;
        swap_item(n, m);
        h.erase(h.find(val));
        arr.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */