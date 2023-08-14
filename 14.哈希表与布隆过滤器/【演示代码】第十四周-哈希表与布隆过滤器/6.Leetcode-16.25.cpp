class Node {
public :
    Node(int key = 0, int value = 0, Node *prev = nullptr, Node *next = nullptr)
    : key(key), value(value), prev(prev), next(next) {}
    int key, value;
    Node *next, *prev;
    Node *remove_this() {
        if (this->prev) this->prev->next = this->next;
        if (this->next) this->next->prev = this->prev;
        this->next = this->prev = nullptr;
        return this;
    }
    void insert_prev(Node *node) {
        node->next = this;
        node->prev = this->prev;
        if (this->prev) this->prev->next = node;
        this->prev = node;
        return ;
    }
};

class HashList {
public :
    int capacity;
    Node head, tail;
    unordered_map<int, Node *> data;
    HashList(int capacity) : capacity(capacity) {
        head.next = &tail;
        tail.prev = &head;
    }
    void put(int key, int value) {
        if (data.find(key) != data.end()) {
            data[key]->value = value;
            data[key]->remove_this();
        } else {
            data[key] = new Node(key, value);
        }
        tail.insert_prev(data[key]);
        if (data.size() > capacity) {
            data.erase(data.find(head.next->key));
            delete head.next->remove_this();
        }
        return ;
    }
    int get(int key) {
        if (data.find(key) == data.end()) return -1;
        data[key]->remove_this();
        tail.insert_prev(data[key]);
        return data[key]->value;
    }
};


class LRUCache {
public:
    HashList h;
    LRUCache(int capacity) : h(capacity) {}
    
    int get(int key) {
        return h.get(key);
    }
    
    void put(int key, int value) {
        h.put(key, value);
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */