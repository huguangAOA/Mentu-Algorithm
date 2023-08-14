struct Node {
    Node() {
        flag = false;
        memset(next, 0, sizeof(next));
    }
    bool flag;
    Node *next[26];
};

struct Trie {
    void insert(string &s) {
        Node *p = &root;
        for (auto x : s) {
            int ind = x - 'a';
            if (p->next[ind] == nullptr) p->next[ind] = new Node();
            p = p->next[ind];
        }
        p->flag = true;
    }
    void get_mark(string &s, int pos, vector<vector<int>> &mark) {
        Node *p = &root;
        for (int i = pos; s[i]; i++) {
            int ind = s[i] - 'a';
            p = p->next[ind];
            if (p == nullptr) break;
            if (p->flag) mark[i + 1].push_back(pos);
        }
        return ;
    }
    Node root;
};

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        Trie tree;
        for (auto s : dictionary) tree.insert(s);
        int n = sentence.size();
        vector<int> dp(n + 1);
        vector<vector<int>> mark(n + 1);
        for (int i = 0; i < n; i++) {
            tree.get_mark(sentence, i, mark);
        }
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            for (auto j : mark[i]) {
                dp[i] = min(dp[i], dp[j]);
            }
        }
        return dp[n];
    }
};