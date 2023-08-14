/*************************************************************************
	> File Name: 10.haffman.cpp
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
using namespace std;

struct node {
    node(int freq = 0, node *lchild = nullptr, node *rchild = nullptr) 
    : freq(freq), ch(0), lchild(lchild), rchild(rchild) {}
    node(int freq = 0, char ch = 0) 
    : freq(freq), ch(ch), lchild(nullptr), rchild(nullptr) {}
    char ch;
    int freq;
    node *lchild, *rchild;
};

struct CMP {
    bool operator()(const node *a, const node *b) const {
        return a->freq < b->freq;
    }
};

void extract_code(node *root, string prefix, vector<string> &code) {
    if (root->ch != 0) {
        code[root->ch] = prefix;
        return ;
    }
    extract_code(root->lchild, prefix + '0', code);
    extract_code(root->rchild, prefix + '1', code);
    return ;
}

int main() {
    int n, freq, freq_arr[128];
    char ch;
    cin >> n;
    multiset<node *, CMP> s;
    for (int i = 0; i < n; i++) {
        cin >> ch >> freq;
        freq_arr[ch] = freq;
        s.insert(new node(freq, ch));
    }
    while (s.size() > 1) {
        node *a = *(s.begin()); s.erase(s.begin());
        node *b = *(s.begin()); s.erase(s.begin());
        s.insert(new node(a->freq + b->freq, a, b));
    }
    node *root = *(s.begin());
    vector<string> code(128);
    extract_code(root, "", code);
    for (int i = 0; i < 128; i++) {
        if (code[i] == "") continue;
        printf("%c(%5d) : %s\n", i, freq_arr[i], code[i].c_str());
    }
    return 0;
}
