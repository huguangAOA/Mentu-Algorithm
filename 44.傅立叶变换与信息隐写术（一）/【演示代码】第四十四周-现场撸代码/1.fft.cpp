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
    void dft(vector<Complex> &a, int n) {
        __transform(a, n);
        return ;
    }
    void idft(vector<Complex> &a, int n) {
        __transform(a, n, -1);
        for (int i = 0; i < n; i++) a[i] /= n;
        return ;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    int k = 1;
    while (k <= n + m + 1) k *= 2;
    vector<Complex> a(k), b(k), c(k);
    for (int i = 0; i <= n; i++) cin >> a[i].r;
    for (int i = 0; i <= m; i++) cin >> b[i].r;
    FastFourierTransform fft;
    fft.dft(a, k);
    fft.dft(b, k);
    cout << "A(x) value : ";
    for (int i = 0; i < k; i++) cout << a[i] << " ";
    cout << endl;
    
    cout << "B(x) value : ";
    for (int i = 0; i < k; i++) cout << b[i] << " ";
    cout << endl;

    for (int i = 0; i < k; i++) c[i] = a[i] * b[i];

    cout << "C(x) value : ";
    for (int i = 0; i < k; i++) cout << c[i] << " ";
    cout << endl;
    
    fft.idft(c, k);

    cout << "C(x) parameters : ";
    for (int i = 0; i < n + m + 1; i++) {
        cout << c[i].r << " " ;
    }
    cout << endl;
    return 0;
}
