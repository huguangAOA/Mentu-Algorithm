/*************************************************************************
	> File Name: 12.HZOJ-48.cpp
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
#define MAX_N 10000
#define MAX_V 10000
int dp[2][MAX_V + 5];
int v[MAX_N + 5], w[MAX_N + 5];

int main() {
    int V, n;
    cin >> n >> V;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        int pre_ind = (i - 1) % 2, ind = i % 2;
        for (int j = 0; j <= V; j++) {
            dp[ind][j] = dp[pre_ind][j];
            if (j >= v[i]) dp[ind][j] = max(dp[ind][j], dp[ind][j - v[i]] + w[i]);
        }
    }
    printf("%d\n", dp[n % 2][V]);
    return 0;
}
