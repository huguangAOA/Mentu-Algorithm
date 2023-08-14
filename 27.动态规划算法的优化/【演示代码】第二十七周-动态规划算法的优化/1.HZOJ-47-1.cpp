/*************************************************************************
	> File Name: 1.HZOJ-47-1.cpp
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
int dp[2][MAX_V + 5];

int main() {
    int V, n;
    cin >> V >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 1, v, w; i <= n; i++) {
        cin >> v >> w;
        int ind = i % 2, pre_ind = (i - 1) % 2;
        for (int j = 0; j <= V; j++) {
            dp[ind][j] = dp[pre_ind][j];
            if (j >= v) dp[ind][j] = max(dp[ind][j], dp[pre_ind][j - v] + w);
        }
    }
    printf("%d\n", dp[n % 2][V]);
    return 0;
}
