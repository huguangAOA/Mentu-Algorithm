/*************************************************************************
	> File Name: 10.HZOJ-46.cpp
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
#include <cstring>
using namespace std;
#define MAX_N 500000
char s[MAX_N + 5];
int dp[MAX_N + 5];
vector<vector<int>> g(MAX_N + 5);

void extract(int i, int j) {
    while (i >= 0 && s[i] == s[j]) {
        g[j + 1].push_back(i);
        i--, j++;
    }
    return ;
}

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        extract(i, i); // odd
        extract(i, i + 1); // even
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (auto j : g[i]) dp[i] = min(dp[i], dp[j] + 1);
    }
    printf("%d\n", dp[n] - 1);
    return 0;
}
