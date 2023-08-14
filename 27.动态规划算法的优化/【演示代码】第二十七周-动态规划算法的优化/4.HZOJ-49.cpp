/*************************************************************************
	> File Name: 4.HZOJ-49.cpp
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
#define MAX_V 100000
int dp[MAX_V + 5];

int main() {
    int n, V;
    cin >> V >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 0, v, w, s; i < n; i++) {
        cin >> v >> w >> s;
        for (int k = 1; s; k *= 2) {
            k = min(k, s);
            int kv = k * v, kw = k * w;
            for (int j = V; j >= kv; j--) {
                dp[j] = max(dp[j], dp[j - kv] + kw);
            }
            s -= k;
        }
    }
    cout << dp[V] << endl;
    return 0;
}
