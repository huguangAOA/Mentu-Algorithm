class Node {
public :
    Node() {
        flag = 0;
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
    int flag;
    Node *next[26];
};
class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *p = root;
        for (auto x : word) {
            int ind = x - 'a';
            if (p->next[ind] == nullptr) p->next[ind] = new Node();
            p = p->next[ind];
        }
        p->flag = true;
        return ;
    }
    
    bool search(string word) {
        Node *p = root;
        for (auto x : word) {
            int ind = x - 'a';
            p = p->next[ind];
            if (p == nullptr) return false;
        }
        return p->flag;
    }
    
    bool startsWith(string prefix) {
        Node *p = root;
        for (auto x : prefix) {
            int ind = x - 'a';
            p = p->next[ind];
            if (p == nullptr) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */