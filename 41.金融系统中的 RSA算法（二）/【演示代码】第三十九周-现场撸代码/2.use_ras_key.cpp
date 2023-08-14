/*************************************************************************
	> File Name: 2.use_ras_key.cpp
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
long long e, d, n;

long long quick_mod(long long a, long long b, long long c) {
    long long ans = 1, temp = a;
    while (b) {
        if (b & 1) ans = ans * temp % c;
        temp = temp * temp % c;
        b >>= 1;
    }
    return ans;
}

int main(int argc, char *argv[]) {
    sscanf(argv[1], "%lld", &e);
    sscanf(argv[2], "%lld", &n);
    sscanf(argv[3], "%lld", &d);
    long long m, c;
    while (cin >> m) {
        c = quick_mod(m, e, n);
        cout << m << "^" << e << " % " << n << " = " << c << endl;
        cout << c << "^" << d << " % " << n << " = " << quick_mod(c, d, n) << endl;
    }
    return 0;
}
