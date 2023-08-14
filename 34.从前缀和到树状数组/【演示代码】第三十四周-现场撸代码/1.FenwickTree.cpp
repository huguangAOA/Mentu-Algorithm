/*************************************************************************
	> File Name: 1.FenwickTree.cpp
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

#define lowbit(x) (x & (-x))
class FenwickTree {
public :
    FenwickTree(int size) : n(size), c(n + 1) {}
    void add(int i, int x) {
        while (i <= n) c[i] += x, i += lowbit(i);
        return ;
    }
    int at(int ind) { return query(ind) - query(ind - 1); }
    int query(int x) {
        int sum = 0;
        while (x) sum += c[x], x -= lowbit(x);
        return sum;
    }
    void output() {
        int len = 0;
        for (int i = 1; i <= n; i++) {
            len += printf("%5d", i);
        }
        printf("\n");
        for (int i = 0; i < len + 6; i++) {
            printf("=");
        }
        printf("\n");
        for (int i = 1; i <= n; i++) {
            printf("%5d", c[i]);
        }
        printf("\n");
        for (int i = 1; i <= n; i++) {
            printf("%5d", query(i) - query(i - 1));
        }
        printf("\n\n\n");
        return ;
    }

private:
    int n; // 下标上限
    vector<int> c;
};

int main() {
    int n;
    cin >> n;
    FenwickTree tree(n);
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        tree.add(i, a);
    }
    tree.output();
    int ind, val;
    while (cin >> ind >> val) {
        cout << "change " << ind << " to " << val << endl;
        tree.add(ind, val - tree.at(ind));
        tree.output();
    }
    return 0;
}
