/*************************************************************************
	> File Name: 11.HZOJ-47.cpp
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
#include <cstring>
#include <set>
#include <vector>
using namespace std;
#define MAX_N 100
#define MAX_V 10000
int dp[MAX_N + 5][MAX_V + 5];
int v[MAX_N + 5], w[MAX_N + 5];

int main() {
    int V, n;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    printf("%d\n", dp[n][V]);
    return 0;
}
