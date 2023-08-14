/*************************************************************************
	> File Name: 13.HZOJ-49.cpp
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
#define MAX_V 100000
int dp[MAX_N + 5][MAX_V + 5];
int v[MAX_N + 5], w[MAX_N + 5], s[MAX_N + 5];

int main() {
    int V, n;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k <= s[i] && k * v[i] <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    printf("%d\n", dp[n][V]);
    return 0;
}
