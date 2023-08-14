/*************************************************************************
	> File Name: 1.solve.cpp
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

int is_prime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int gcd(int a, int b) {
    if (b) return gcd(b, a % b);
    return a;
}

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!is_prime(gcd(i, j))) continue;
            ans += 1;
            cout << i << " " << j << endl;
        }
    } 
    cout << "total : " << ans << endl;
    return 0;
}
