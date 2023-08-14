class Node {
public :
    Node() {
        flag = false;
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }
    bool flag;
    Node *next[26];
};

class Trie {
public :
    void insert(string &s) {
        Node *p = &root;
        for (auto x : s) {
            int ind = x - 'a';
            if (p->next[ind] == nullptr) p->next[ind] = new Node();
            p = p->next[ind];
        }
        p->flag = true;
        return ;
    }
    bool __search(string &s, int pos, Node *p, int n) {
        if (pos == s.size()) return p->flag && n == 0;
        int ind = s[pos] - 'a';
        if (p->next[ind] && __search(s, pos + 1, p->next[ind], n)) return true;
        if (n) {
            for (int i = 0; i < 26; i++) {
                if (i == ind || p->next[i] == nullptr) continue;
                if (__search(s, pos + 1, p->next[i], n - 1)) return true;
            }
        }
        return false;
    }
    bool search(string &s, int n) {
        return __search(s, 0, &root, n);
    }

private:
    Node root;

};


class MagicDictionary {
public:
    MagicDictionary() {}
    Trie tree;
    void buildDict(vector<string> dictionary) {
        for (auto s : dictionary) tree.insert(s);
        return ;
    }
    
    bool search(string searchWord) {
        return tree.search(searchWord, 1);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */