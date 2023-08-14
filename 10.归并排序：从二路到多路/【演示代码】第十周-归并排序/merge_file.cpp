/*************************************************************************
	> File Name: merge_file.cpp
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

struct Data {
    FILE *fin;
    int val, flag;
};

int main(int argc, char *argv[]) {
    int n = argc - 1;
    Data *data = (Data *)malloc(sizeof(Data) * n);
    for (int i = 1; i <= n; i++) {
        data[i - 1].fin = fopen(argv[i], "r");
        if (fscanf(data[i - 1].fin, "%d", &data[i - 1].val) == EOF) {
            data[i - 1].flag = 1;
        } else {
            data[i - 1].flag = 0;
        }
    }
    FILE *fout = fopen("output", "w");
    while (1) {
        int flag = 0;
        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (data[i].flag) continue;
            if (ind == -1 || data[i].val < data[ind].val) {
                ind = i;
            }
        }
        if (ind != -1) {
            fprintf(fout, "%d\n", data[ind].val);
            if (fscanf(data[ind].fin, "%d", &data[ind].val) == EOF) {
                data[ind].flag = 1;
            } else {
                data[ind].flag = 0;
            }
            flag = 1;
        }
        if (flag == 0) break;
    }
    return 0;
}
