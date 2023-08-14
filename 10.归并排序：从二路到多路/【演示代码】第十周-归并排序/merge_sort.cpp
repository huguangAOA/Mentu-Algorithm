/*************************************************************************
	> File Name: merge_sort.cpp
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


void merge_sort(int *arr, int l, int r) {
    if (l >= r) return ;
    int mid = (l + r) >> 1;
    //cout << endl;
    //cout << "sort " << l << " <--> " << r << " : " << endl;
    //for (int i = l; i <= r; i++) cout << arr[i] << " ";
    //cout << endl;
    merge_sort(arr, l, mid); // left sort
    merge_sort(arr, mid + 1, r); // right sort
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int k = 0, p1 = l, p2 = mid + 1;
    while (p1 <= mid || p2 <= r) {
        if ((p2 > r) || (p1 <= mid && arr[p1] <= arr[p2])) {
            temp[k] = arr[p1]; k += 1, p1 += 1;
        } else {
            temp[k] = arr[p2]; k += 1, p2 += 1;
        }
    }
    for (int i = l; i <= r; i++) arr[i] = temp[i - l];
    //for (int i = l; i <= r; i++) cout << arr[i] << " ";
    //cout << endl;
    free(temp);
    return ;
}

int main() {
    int n;
    int arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
