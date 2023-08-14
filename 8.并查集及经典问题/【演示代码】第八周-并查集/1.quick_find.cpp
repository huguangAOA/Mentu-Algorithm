/*************************************************************************
	> File Name: quick_find.cpp
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

class UnionSet {
public :
    int *color, n;
    UnionSet(int n) : n(n) {
        color = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            color[i] = i;
        }
    }
    int find(int x) {
        return color[x];
    }
    void merge(int a, int b) {
        if (color[a] == color[b]) return ;
        int cb = color[b];
        for (int i = 0; i <= n; i++) {
            if (color[i] == cb) color[i] = color[a];
        }
        return ;
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    UnionSet u(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        switch (a) {
            case 1: u.merge(b, c); break;
            case 2: if (u.find(b) == u.find(c)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
