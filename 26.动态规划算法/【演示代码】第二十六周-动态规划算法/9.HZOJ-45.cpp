/*************************************************************************
	> File Name: 9.HZOJ-45.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define MAX_N 1000
char s1[MAX_N + 5], s2[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];

int main() {
    scanf("%s%s", s1, s2);
    dp[0][0] = 0;
    int n = strlen(s1), m = strlen(s2);
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
