class Node {
public:
    Node(int key = 0, Node *next = nullptr) : key(key), next(next) {}
    int key;
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

class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<Node> data;
    MyHashSet() : data(100) {}
    
    int hash_func(int key) { return key & 0x7fffffff; }

    void add(int key) {
        if (contains(key)) return ;
        int ind = hash_func(key) % data.size();
        data[ind].insert_after(new Node(key));
        return ;
    }
    
    void remove(int key) {
        int ind = hash_func(key) % data.size();
        Node *p = &data[ind];
        while (p->next && p->next->key != key) p = p->next;
        p->remove_after();
        return ;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int ind = hash_func(key) % data.size();
        Node *p = data[ind].next;
        while (p && p->key != key) p = p->next;
        return p != nullptr;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */