class Node {
public:
    Node(int key = 0, int value = 0, Node *next = nullptr) 
    : key(key), value(value), next(next) {}
    int key, value;
    Node *next;
    void insert_after(Node *node) {
        node->next = this->next;
        this->next = node;
        return ;
    }
    void remove_after() {
        if (this->next == nullptr) return ;
        Node *p = this->next;
        this->next = this->next->next;
        delete p;
        return ;
    }
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<Node> data;
    MyHashMap() : data(100) {}
    int hash_func(int key) { return key & 0x7fffffff; }
    /** value will always be non-negative. */
    void put(int key, int value) {
        int ind = hash_func(key) % data.size();
        Node *p = &data[ind];
        while (p->next && p->next->key != key) p = p->next;
        if (p->next) {
            p->next->value = value;
        } else {
            p->insert_after(new Node(key, value));
        }
        return ;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int ind = hash_func(key) % data.size();
        Node *p = data[ind].next;
        while (p && p->key != key) p = p->next;
        if (p == nullptr) return -1;
        return p->value;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int ind = hash_func(key) % data.size();
        Node *p = &data[ind];
        while (p->next && p->next->key != key) p = p->next;
        p->remove_after();
        return ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */