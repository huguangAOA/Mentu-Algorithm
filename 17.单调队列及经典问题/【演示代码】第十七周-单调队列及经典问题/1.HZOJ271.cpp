/*************************************************************************
	> File Name: HZOJ271.cpp
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
    int n, k;
    vector<int> arr;
    cin >> n >> k;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    deque<int> q;
    for (int i = 0; i < n; i++) {
        while (q.size() && arr[q.back()] > arr[i]) q.pop_back();
        q.push_back(i);
        if (i - q.front() == k) q.pop_front();
        if (i + 1 < k) continue;
        if (i + 1 > k) cout << " ";
        cout << arr[q.front()];
    }
    cout << endl;
    q.clear();
    for (int i = 0; i < n; i++) {
        while (q.size() && arr[q.back()] < arr[i]) q.pop_back();
        q.push_back(i);
        if (i - q.front() == k) q.pop_front();
        if (i + 1 < k) continue;
        if (i + 1 > k) cout << " ";
        cout << arr[q.front()];
    }
    cout << endl;
    return 0;
}
