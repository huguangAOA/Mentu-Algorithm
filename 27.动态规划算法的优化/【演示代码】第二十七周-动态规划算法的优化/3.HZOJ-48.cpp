/*************************************************************************
	> File Name: 2.HZOJ-47-2.cpp
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
int dp[MAX_V + 5];

int main() {
    int V, n;
    cin >> n >> V;
    memset(dp, 0, sizeof(dp));
    for (int i = 1, v, w; i <= n; i++) {
        cin >> v >> w;
        for (int j = v; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
