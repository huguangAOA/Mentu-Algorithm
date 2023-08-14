/*************************************************************************
	> File Name: 1.make_rsa_key.cpp
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
#define MAX_N 50000
long long prime[MAX_N + 5] = {0};
void init_prime() {
    for (long long i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (long long j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

long long gcd(long long a, long long b) {
    if (b) return gcd(b, a % b);
    return a;
}

long long get_inv(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long r = get_inv(b, a % b, y, x);
    y -= (a / b) * x;
    return r;
}

int main() {
    srand(time(0));
    init_prime();
    cout << "prime[0] = " << prime[0] << endl;
    cout << "last prime : " << prime[prime[0]] << endl;
    long long p, q, p_ind, q_ind;
    do {
        p_ind = rand() % 100 + prime[0] - 99;
        q_ind = rand() % 100 + prime[0] - 99;
    } while (p_ind == q_ind);
    p = prime[p_ind];
    q = prime[q_ind];
    long long n = p * q, phi_n = (p - 1) * (q - 1);
    long long e, d, y;
    do {
        e = rand() % phi_n;
    } while (e == 0 || gcd(e, phi_n) != 1);
    get_inv(e, phi_n, d, y);
    d = (((d % phi_n) + phi_n) % phi_n);
    assert(e * d % phi_n == 1);
    cout << "./a.out " << e << " " << n << " " << d << " " << n << endl;
    return 0;
}
