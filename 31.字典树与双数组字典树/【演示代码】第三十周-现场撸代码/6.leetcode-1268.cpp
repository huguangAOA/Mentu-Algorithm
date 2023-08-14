#define BASE 26
class node {
public :
    node() {
        flag = false;
        for (int i = 0; i < BASE; i++) next[i] = nullptr;
    }
    ~node() {}
    set<string> s;
    bool flag;
    node *next[BASE];
};

class Trie {
public :
    Trie() {
        root = new node();
    }
    bool insert(string word) {
        node *p = root;
        for (auto x : word) {
            int ind = x - 'a';
            if (p->next[ind] == nullptr) p->next[ind] = new node();
            p = p->next[ind];
            p->s.insert(word);
            if (p->s.size() > 3) {
                auto iter = p->s.end();
                iter--;
                p->s.erase(iter);
            }
        }
        if (p->flag) return false;
        p->flag = true;
        return true;
    }
    vector<vector<string>> search(string word) {
        node *p = root;
        vector<vector<string>> ret;
        for (auto x : word) {
            if (p == nullptr) {
                ret.push_back(vector<string>());
                continue;
            }
            int ind = x - 'a';
            p = p->next[ind];
            vector<string> temp;
            if (p != nullptr) {
                for (auto s : p->s) temp.push_back(s);
            }
            ret.push_back(temp);
        }
        return ret;
    }
    static void clearTrie(node *root) {
        if (root == nullptr) return ;
        for (int i = 0; i < BASE; i++) clearTrie(root->next[i]);
        delete root;
        return ;
    }
    ~Trie() {
        clearTrie(root);
    }
private:
    node *root;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie tree;
        for (auto s : products) tree.insert(s);
        return tree.search(searchWord);
    }
};