/*************************************************************************
	> File Name: 3.phi.cpp
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

int phi(int n) {
    int x = 2, ans = n;
    while (x * x <= n) {
        if (n % x == 0) ans -= ans / x;
        while (n % x == 0) n /= x;
        x += 1;
    }
    if (n != 1) ans -= ans / n;
    return ans;
}

int main() {
    int n;
    while (cin >> n) {
        cout << "phi(" << n << ") = " << phi(n) << endl;
    }
    return 0;
}
