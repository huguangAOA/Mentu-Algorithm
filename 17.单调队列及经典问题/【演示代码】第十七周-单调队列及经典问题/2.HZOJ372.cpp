/*************************************************************************
	> File Name: HZOJ372.cpp
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    deque<int> q1, q2;
    int p;
    for (p = 0; p < n; p++) {
        while (q1.size() && a[p] < q1.back()) q1.pop_back();
        while (q2.size() && b[p] < q2.back()) q2.pop_back();
        q1.push_back(a[p]);
        q2.push_back(b[p]);
        if (q1.size() != q2.size()) break;
    }
    cout << p << endl;
    return 0;
}
