/*************************************************************************
	> File Name: 3.calc.cpp
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

int calc(string &s, int l, int r) {
    #define INF 0x3f3f3f3f
    int pos = -1, pri = INF - 1, temp = 0, cur_pri;
    for (int i = l; i <= r; i++) {
        cur_pri = INF;
        switch (s[i]) {
            case '(': temp += 100; break;
            case ')': temp -= 100; break;
            case '+': 
            case '-': cur_pri = temp + 1; break;
            case '*': 
            case '/': cur_pri = temp + 2; break;
        }
        if (cur_pri <= pri) {
            pos = i;
            pri = cur_pri;
        }
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] < '0' || s[i] > '9') continue;
            num = num * 10 + (s[i] - '0');
        }
        return num;
    }
    int a = calc(s, l, pos - 1);
    int b = calc(s, pos + 1, r);
    cout << a << " " << s[pos] << " " << b << endl;
    switch (s[pos]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return -1;
    #undef INF
}

int main() {
    string exp_str;
    cin >> exp_str;
    cout << exp_str << " : ";
    cout << calc(exp_str, 0, exp_str.size() - 1) << endl;
    return 0;
}
