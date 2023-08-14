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
#define MAX_CNT 10000
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
} trie[MAX_CNT];
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

int *base, *check, da_root = 1;

int getBaseValue(int root, int *base, int *check) {
    int b = 1, flag = 0;
    while (flag == 0) {
        flag = 1;
        b += 1;
        for (int i = 0; i < BASE; i++) {
            if (trie[root].next[i] == 0) continue;
            if (check[b + i] == 0) continue;
            flag = 0;
            break;
        }
    }
    return b;
}

int ConvertToDoubleArrayTrie(int root, int da_root, int *base, int *check) {
    if (root == 0) return 0;
    int max_ind = da_root;
    base[da_root] = getBaseValue(root, base, check);
    for (int i = 0; i < BASE; i++) {
        if (trie[root].next[i] == 0) continue;
        check[base[da_root] + i] = da_root;
        if (trie[trie[root].next[i]].flag) {
            check[base[da_root] + i] = -da_root;
        }
    }
    for (int i = 0; i < BASE; i++) {
        if (trie[root].next[i] == 0) continue;
        max_ind = max(
            max_ind, 
            ConvertToDoubleArrayTrie(
                trie[root].next[i], 
                base[da_root] + i, 
                base, check
            )
        );
    }
    return max_ind;
}

bool searchDATrie(string s) {
    int p = da_root;
    for (auto x : s) {
        int ind = x - 'a';
        if (abs(check[base[p] + ind]) != p) return false;
        p = base[p] + ind;
    }
    return check[p] < 0;
}

int main() {
    cout << "trie version 4 : " << endl;
    clearTrie();
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        insert(s);
    }
    base  = new int[MAX_CNT];
    check = new int[MAX_CNT];
    memset(base, 0, sizeof(int) * MAX_CNT);
    memset(check, 0, sizeof(int) * MAX_CNT);
    int max_ind = ConvertToDoubleArrayTrie(root, da_root, base, check);
    printf("trie usage : %lu byte\n", cnt * sizeof(node));
    printf("double array trie usage : %lu byte\n", (max_ind + 1) * sizeof(int) * 2);
    while (cin >> s) {
        cout << "find " << s << ", from trie : " << search(s) << endl;
        cout << "find " << s << ", from da trie : " << searchDATrie(s) << endl;
    }
    return 0;
}
