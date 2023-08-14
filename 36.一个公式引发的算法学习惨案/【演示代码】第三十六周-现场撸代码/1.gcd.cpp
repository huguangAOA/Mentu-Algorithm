/*************************************************************************
	> File Name: 1.gcd.cpp
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

int gcd(int a, int b) {
    cout << "gcd(" << a << ", " << b << ") = ";
    if (b) return gcd(b, a % b);
    return a;
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << gcd(a, b) << endl;
    }
    return 0;
}
