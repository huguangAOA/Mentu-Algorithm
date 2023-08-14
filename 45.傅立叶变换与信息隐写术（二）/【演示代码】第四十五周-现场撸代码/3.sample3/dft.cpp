/*************************************************************************
	> File Name: 1.fft.cpp
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

#define PI acos(-1)

struct Complex {
    Complex(double r = 0, double i = 0) : r(r), i(i) {}
    double real() { return r; };
    double m() { return sqrt(r * r + i * i); }
    Complex conj() { return Complex(r, -i); }
    Complex &operator/=(double n) { r /= n, i /= n;  return *this; }
    Complex operator+(const Complex &obj) {
        return Complex(r + obj.r, i + obj.i);
    }
    Complex operator*(const Complex &obj) {
        return Complex(r * obj.r - i * obj.i, r * obj.i + i * obj.r);
    }
    Complex operator-(const Complex &obj) {
        return Complex(r - obj.r, i - obj.i);
    }
    void clear() { r = i = 0; }

    double r, i;
};

ostream &operator<<(ostream &out, const Complex &obj) {
    cout << obj.r << "+" << obj.i << "i";
    return out;
}

struct FastFourierTransform {
    void __transform(vector<Complex> &a, int n, int type = 1) {
        if (n == 1) return ;
        int m = n / 2;
        
        // P0, P1
        vector<Complex> a0(m), a1(m);
        for (int i = 0; i < m; i++) a0[i] = a[i * 2], a1[i] = a[i * 2 + 1];
        __transform(a0, m, type);
        __transform(a1, m, type);
        
        // merge P0, P1
        Complex w(1, 0), wn(cos(2.0 * PI / n), type * sin(2.0 * PI / n));
        for (int k = 0; k < m; k++) {
            a[k] = a0[k] + w * a1[k];
            a[k + m] = a0[k] - w * a1[k];
            w = w * wn;
        }
        return ;
    }
    vector<Complex> dft(vector<Complex> &a, int n) {
        vector<Complex> ta(a);
        __transform(ta, n, -1);
        return ta;
    }
    vector<Complex> idft(vector<Complex> &a, int n) {
        vector<Complex> ta(a);
        __transform(ta, n);
        for (int i = 0; i < n; i++) ta[i] /= n;
        return ta;
    }
};

int main() {
    int n, N = 1;
    cin >> n;
    while (N < n) N *= 2;
    vector<Complex> g(N);
    for (int i = 0; i < n; i++) cin >> g[i].r;
    FastFourierTransform fft;
    vector<Complex> tg = fft.dft(g, N);
    for (int j = N / 10, i = j; i < N - j; i++) tg[i].clear();
    vector<Complex> itg = fft.idft(tg, N);
    for (int i = 0; i < n; i++) cout << itg[i].r << endl;
    return 0;
}
