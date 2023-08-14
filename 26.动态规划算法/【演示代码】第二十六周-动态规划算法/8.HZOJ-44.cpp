/*************************************************************************
	> File Name: 8.HZOJ-44.cpp
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
#define MAX_N 1000000
int arr[MAX_N + 5], dp[MAX_N + 5];


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] >= arr[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
