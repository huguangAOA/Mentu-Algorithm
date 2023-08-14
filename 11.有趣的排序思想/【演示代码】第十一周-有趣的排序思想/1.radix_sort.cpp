/*************************************************************************
	> File Name: 1.radix_sort.cpp
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

#define low16(a) ((a) & 0xffff)
#define __high16(a) (((a) & 0xffff0000) >> 16)
#define high16(a) (__high16(a) > 32767 ? (__high16(a) - 32768) : (__high16(a) + 32768))

void radix_sort(int *arr, int n) {
    int cnt[65536] = {0};
    int *temp = (int *)malloc(sizeof(int) * n);
    // low 16 bit sort
    for (int i = 0; i < n; i++) cnt[low16(arr[i])] += 1; // count
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];  // prefix sum
    for (int i = n - 1; i >= 0; --i) temp[--cnt[low16(arr[i])]] = arr[i]; // placement
    // init cnt
    for (int i = 0; i < 65536; i++) cnt[i] = 0;
    // high 16 bit sort
    for (int i = 0; i < n; i++) cnt[high16(temp[i])] += 1; // count
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];  // prefix sum
    for (int i = n - 1; i >= 0; --i) arr[--cnt[high16(temp[i])]] = temp[i];
    free(temp);
    return ;
}

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return ;
}

int *getRandData(int n) {
    int *temp = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) temp[i] = (rand() % 2 ? -1 : 1) * (rand());
    return temp;
}

int main() {
    #define MAX_N 20
    int *arr = getRandData(MAX_N);
    output(arr, MAX_N);
    radix_sort(arr, MAX_N);
    output(arr, MAX_N);
    free(arr);
    return 0;
}
