/*************************************************************************
	> File Name: sample.cpp
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

void output(vector<int> &arr, const char *msg) {
    printf("%s", msg);
    for (auto x : arr) {
        printf("%5d", x);
    }
    printf("\n");
    return ;
}

int main() {
    int n;
    cin >> n;
    vector<int> ind(n);
    vector<int> arr(n);
    vector<int> pre(n), nxt(n);
    stack<int> s;
    for (int i = 0; i < n; i++) ind[i] = i;
    for (int i = 0, a; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        while (s.size() && arr[i] < arr[s.top()]) {
            nxt[s.top()] = i;
            s.pop();
        }
        if (s.size() == 0) pre[i] = -1;
        else pre[i] = s.top();
        s.push(i);
    }
    while (s.size()) nxt[s.top()] = n, s.pop();
    output(ind, "ind : ");
    output(arr, "now : ");
    output(pre, "pre : ");
    output(nxt, "nxt : ");
    return 0;
}
