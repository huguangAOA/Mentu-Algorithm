/*************************************************************************
	> File Name: 248.cpp
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

long long merge_sort(vector<int> &arr, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) >> 1;
    long long cnt = 0;
    cnt += merge_sort(arr, l, mid);
    cnt += merge_sort(arr, mid + 1, r);
    vector<int> temp(r - l + 1);
    int k = 0, p1 = l, p2 = mid + 1;
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || (p1 <= mid && arr[p1] <= arr[p2])) {
            temp[k++] = arr[p1++];
        } else {
            cnt += (mid - p1 + 1);
            temp[k++] = arr[p2++];
        }
    }
    for (int i = l; i <= r; i++) arr[i] = temp[i - l];
    return cnt;
}

void solve(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << merge_sort(arr, 0, arr.size() - 1) << endl;
    return ;
}

int main() {
    int x;
    while (cin >> x) {
        if (x == 0) break;
        solve(x);
    }
    return 0;
}
