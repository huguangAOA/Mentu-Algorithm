/*************************************************************************
	> File Name: sort.cpp
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

void insert_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            arr[j] ^= arr[j - 1];
            arr[j - 1] ^= arr[j];
            arr[j] ^= arr[j - 1];
            j--;
        }
    }
    return ;
}

void select_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[k]) k = j;
        }
        swap(arr[i], arr[k]);
    }
    return ;
}

void bubble_sort(int *arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return ;
}


int main() {
    
    return 0;
}
