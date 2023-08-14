/*************************************************************************
	> File Name: 2.ex_gcd.cpp
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

int ex_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int r = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return r;
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        int x, y;
        int c = ex_gcd(a, b, x, y);
        cout << a << " * " << x << " + " << b << " * " << y << " = " << c << endl;
    }
    return 0;
}
