/*************************************************************************
	> File Name: 1.trie_match.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <unordered_set>
using namespace std;

#define BASE 26
struct Node {
    Node() : flag(false), fail(nullptr) {
        for (int i = 0; i < BASE; i++) next[i] = nullptr;
        return ;
    }
    string *s;
    bool flag;
    Node *fail;
    Node *next[BASE];
};

struct Automaton {
public :
    Automaton() = default;
    void insert(string s) {
        Node *p = &root;
        for (auto x : s) {
            int ind = x - 'a';
            if (p->next[ind] == nullptr) p->next[ind] = new Node();
            p = p->next[ind];
        }
        if (p->flag == false) {
            p->flag = true;
            p->s = new string(s);
        }
        return ;
    }
    void build_ac() {
        queue<Node *> q;
        for (int i = 0; i < BASE; i++) {
            if (root.next[i] == nullptr) {
                root.next[i] = &root;
                continue;
            }
            root.next[i]->fail = &root;
            q.push(root.next[i]);
        }
        while (!q.empty()) {
            Node *now = q.front(), *p;
            q.pop();
            for (int i = 0; i < BASE; i++) {
                if (now->next[i] == nullptr) {
                    now->next[i] = now->fail->next[i];
                    continue;
                }
                now->next[i]->fail = now->fail->next[i];
                q.push(now->next[i]);
            }
        }
        return ;
    }
    unordered_set<string> match(string &s) {
        int cnt = 0;
        unordered_set<string> ret;
        Node *p = &root, *k;
        for (auto x : s) {
            // 状态转移
            int ind = x - 'a';
            p = p->next[ind], cnt += 1;
            // 提取结果
            k = p;
            while (k) {
                if (k->flag) ret.insert(*(k->s));
                k = k->fail;
            }
        }
        cout << "Total operator : " << cnt << endl;
        return ret;
    }
private:
    Node root;
};

int main() {
    int n;
    Automaton tree;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        tree.insert(s);
    }
    tree.build_ac();
    cin >> s;
    auto ans = tree.match(s);
    for (auto x : ans) cout << x << endl;
    cout << "find : " << ans.size() << " item(s)" << endl;
    return 0;
}
