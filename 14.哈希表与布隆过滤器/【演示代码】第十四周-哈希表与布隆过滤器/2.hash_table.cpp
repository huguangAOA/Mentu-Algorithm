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

class HashTable {
public:
    HashTable(int n = 100) : flag(n), data(n), cnt(0) {}
    void insert(string s) {
        int ind = hash_func(s) % data.size(); // 计算哈希值
        recalc_ind(ind, s); // 冲突处理
        if (flag[ind] == false) {
            data[ind] = s;
            flag[ind] = true;
            cnt += 1;
            if (cnt * 100 > data.size() * 75) {
                expand();
            }
        } else if (data[ind] != s) {
            buff.insert(s);
        }
        return ;
    }
    bool find(string s) {
        int ind = hash_func(s) % data.size(); // 计算哈希值
        recalc_ind(ind, s); // 冲突处理
        if (flag[ind] == false) return false;
        if (data[ind] == s) return true;
        return buff.find(s) != buff.end();
    }

private:
    int cnt;
    vector<string> data;
    vector<bool> flag;
    set<string> buff;
    
    void expand() {
        int n = data.size() * 2;
        HashTable h(n);
        for (int i = 0; i < data.size(); i++) {
            if (flag[i] == false) continue;
            h.insert(data[i]);
        }
        for (auto x : buff) {
            h.insert(x);
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
