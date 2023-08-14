/*************************************************************************
	> File Name: weighted_quick_union.cpp
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
    int *fa, *size, n;
    UnionSet(int n) : n(n) {
        fa   = new int[n + 1];
        size = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            size[i] = 1;
        }
    }
    int find(int x) {
        if (fa[x] == x) return x;
        int root = find(fa[x]);
        fa[x] = root;
        return root;
    }
    void merge(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return ;
        if (size[ra] < size[rb]) {
            fa[ra] = rb;
            size[rb] += size[ra];
        } else {
            fa[rb] = ra;
            size[ra] += size[rb];
        }
        return ;
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionSet u(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: u.merge(b, c); break;
            case 2: if (u.find(b) == u.find(c)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
