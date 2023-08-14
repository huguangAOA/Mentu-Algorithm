/*************************************************************************
	> File Name: 1.hash_table.cpp
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

class Node {
public :
    Node(string data = "", Node *next = nullptr) : data(), next(nullptr) {}
    string data;
    Node *next;
    void insert(Node *node) {
        node->next = this->next;
        this->next = node;
        return ;
    }
};

class HashTable {
public:
    HashTable(int n = 100) : data(n), cnt(0) {}
    void insert(string s) {
        int ind = hash_func(s) % data.size(); // 计算哈希值
        recalc_ind(ind, s); // 冲突处理
        Node *p = &data[ind];
        while (p->next && p->next->data != s) p = p->next;
        if (p->next == nullptr) {
            p->insert(new Node(s));
            cnt += 1;
            if (cnt > data.size() * 3) expand();
        }
        return ;
    }
    bool find(string s) {
        int ind = hash_func(s) % data.size(); // 计算哈希值
        recalc_ind(ind, s); // 冲突处理
        Node *p = data[ind].next;
        while (p && p->data != s) p = p->next;
        return p != nullptr;
    }

private:
    int cnt;
    vector<Node> data;
    
    void expand() {
        int n = data.size() * 2;
        HashTable h(n);
        for (int i = 0; i < data.size(); i++) {
            Node *p = data[i].next;
            while (p) {
                h.insert(p->data);
                p = p->next;
            }
        }
        *this = h;
        return ;
    }
    int hash_func(string &s) {
        int seed = 131, hash = 0;
        for (int i = 0; s[i]; i++) {
            hash = hash * seed + s[i];
        }
        return hash & 0x7fffffff;
    }
    void recalc_ind(int &ind, string &s) {
        return ;
    }
};

int main() {
    int op;
    string s;
    HashTable h;
    while (cin >> op >> s) {
        switch (op) {
            case 1: h.insert(s); break;
            case 2: cout << "find " << s << " : " << h.find(s) << endl; break;
        }
    }
    return 0;
}
