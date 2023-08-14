/*************************************************************************
	> File Name: 2.u.cpp
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

#define MAX_N 10000
int mu[MAX_N + 5] = {0};
int prime[MAX_N + 5] = {0};

void init_prime(int n) {
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
            mu[i * prime[j]] = -mu[i];
        }
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    init_prime(n);
    for (int i = 1; i <= n; i++) {
        cout << "mu[" << i << "] = " << mu[i] << endl;
    }
    return 0;
}
