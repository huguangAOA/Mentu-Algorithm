/*************************************************************************
	> File Name: map.cpp
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

int main() {
    set<int> h;
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        cout << "insert val = " << val << endl;
        h.insert(val);
        for (auto x : h) {
            cout << x << " ";
        }
        cout << endl;
        auto iter = h.find(val);
        if (iter == h.begin()) {
            cout << val << " is first" << endl;
        } else {
            --iter;
            cout << *iter << " is the biggest before " << val << endl; 
        }
    }
    return 0;
}
