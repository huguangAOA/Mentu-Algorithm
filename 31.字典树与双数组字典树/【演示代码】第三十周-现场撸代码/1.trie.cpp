/*************************************************************************
	> File Name: 1.trie.cpp
	> Author: huguang
mZ> Mail: hug@haizeix.com
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
using namespace std;

#define BASE 26
class node {
public :
    node() {
        flag = false;
        for (int i = 0; i < BASE; i++) next[i] = nullptr;
    }
    ~node() {}
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
        }
        if (p->flag) return false;
        p->flag = true;
        return true;
    }
    bool search(string word) {
        node *p = root;
        for (auto x : word) {
            int ind = x - 'a';
            p = p->next[ind];
            if (p == nullptr) return false;
        }
        return p->flag;
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

int main() {
    Trie t;
    int op;
    string s;
    while (cin >> op >> s) {
        switch (op) {
            case 1: t.insert(s); break;
            case 2: cout << "search word = " << s << ", result : "  << t.search(s) << endl;
        }
    }
    return 0;
}
