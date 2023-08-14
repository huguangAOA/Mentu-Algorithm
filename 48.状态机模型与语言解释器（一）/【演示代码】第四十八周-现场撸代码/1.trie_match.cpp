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
    Node() : flag(false) {
        for (int i = 0; i < BASE; i++) next[i] = nullptr;
        return ;
    }
    bool flag;
    Node *next[BASE];
};

struct Trie {
public :
    Trie() = default;
    void insert(string s) {
        Node *p = &root;
        for (auto x : s) {
            int ind = x - 'a';
            if (p->next[ind] == nullptr) p->next[ind] = new Node();
            p = p->next[ind];
        }
        p->flag = true;
        return ;
    }
    unordered_set<string> match(string &s) {
        int cnt = 0;
        unordered_set<string> ret;
        for (int i = 0, n = s.size(); i < n; i++) {
            Node *p = &root;
            cnt += 1;
            for (int j = i; s[j]; j++) {
                int ind = s[j] - 'a';
                if (p->next[ind] == nullptr) break;
                p = p->next[ind];
                cnt += 1;
                if (p->flag) ret.insert(s.substr(i, j - i + 1));
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
    Trie tree;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        tree.insert(s);
    }
    cin >> s;
    auto ans = tree.match(s);
    for (auto x : ans) cout << x << endl;
    cout << "find : " << ans.size() << " item(s)" << endl;
    return 0;
}
