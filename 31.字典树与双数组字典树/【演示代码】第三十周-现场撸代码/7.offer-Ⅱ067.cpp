class Node {
public :
    Node() {
        for (int i = 0; i < 2; i++) {
            next[i] = nullptr;
        }
    }
    Node *next[2];
};
class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(int x) {
        Node *p = root;
        for (int i = 30; i >= 0; --i) {
            int ind = !!(x & (1 << i));
            if (p->next[ind] == nullptr) p->next[ind] = new Node();
            p = p->next[ind];
        }
        return ;
    }
    
    int search(int x) {
        Node *p = root;
        int ans = 0;
        for (int i = 30; i >= 0; --i) {
            int ind = !!(x & (1 << i));
            if (p->next[!ind]) {
                ans |= (1 << i);
                p = p->next[!ind];
            } else {
                p = p->next[ind];
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie tree;
        for (auto x : nums) tree.insert(x);
        int ans = 0;
        for (auto x : nums) ans = max(ans, tree.search(x));
        return ans; 
    }
};