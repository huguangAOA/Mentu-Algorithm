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
    int flag;
    int next[BASE];
    void clear() {
        flag = 0;
        for (int i = 0; i < BASE; i++) {
            next[i] = 0;
        }
    }
} trie[10000];
int cnt, root;
void clearTrie() {
    cnt = 2, root = 1;
    trie[root].clear();
    return ;
}

int getNewNode() {
    trie[cnt].clear();
    return cnt++;
}

void insert(string s) {
    int p = root;
    for (auto x : s) {
        int ind = x - 'a';
        if (trie[p].next[ind] == 0) trie[p].next[ind] = getNewNode();
        p = trie[p].next[ind];
    }
    trie[p].flag = 1;
    return ;
}

bool search(string s) {
    int p = root;
    for (auto x : s) {
        int ind = x - 'a';
        p = trie[p].next[ind];
        if (p == 0) return false;
    }
    return trie[p].flag;
}

int main() {
    cout << "trie version 3 : " << endl;
    clearTrie();
    int op;
    string s;
    while (cin >> op >> s) {
        switch (op) {
            case 1: insert(s); break;
            case 2: cout << "search word = " << s << ", result : "  << search(s) << endl;
        }
    }
    return 0;
}
