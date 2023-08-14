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
    void output() {
        __output(root, "");
        return ;
    }
    static void __output(node *root, string s) {
        if (root == nullptr) return ;
        if (root->flag) cout << "find : " << s << endl;
        for (int i = 0; i < BASE; i++) {
            __output(root->next[i], s + char(i + 'a'));
        }
        return ; 
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
    int n;
    cin >> n;
    string s;
    Trie t;
    for (int i = 0; i < n; i++) {
        cin >> s;
        t.insert(s);
    }
    t.output();
    return 0;
}
