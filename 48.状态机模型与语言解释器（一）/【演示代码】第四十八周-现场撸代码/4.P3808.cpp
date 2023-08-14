/*************************************************************************
	> File Name: 1.trie_match.cpp
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
#include <unordered_set>
using namespace std;

#define BASE 26
#define MAX_N 1000000
struct Node {
    Node() : flag(0), fail(0) {
        for (int i = 0; i < BASE; i++) next[i] = 0;
        return ;
    }
    int flag;
    int fail;
    int next[BASE];
};

Node tree[MAX_N + 5];
int node_buff_cnt = 1;
int getNewNode() {
    return ++node_buff_cnt;
}

struct Automaton {
public :
    Automaton() : root(1) {}
    void insert(char *s) {
        int p = root;
        for (int i = 0; s[i]; i++) {
            int ind = s[i] - 'a';
            if (tree[p].next[ind] == 0) tree[p].next[ind] = getNewNode();
            p = tree[p].next[ind];
        }
        tree[p].flag += 1;
        return ;
    }
    void build_ac() {
        queue<int> q;
        for (int i = 0; i < BASE; i++) {
            if (tree[root].next[i] == 0) {
                tree[root].next[i] = root;
                continue;
            }
            tree[tree[root].next[i]].fail = root;
            q.push(tree[root].next[i]);
        }
        while (!q.empty()) {
            int now = q.front(), p;
            q.pop();
            for (int i = 0; i < BASE; i++) {
                if (tree[now].next[i] == 0) {
                    tree[now].next[i] = tree[tree[now].fail].next[i];
                    continue;
                }
                tree[tree[now].next[i]].fail = tree[tree[now].fail].next[i];
                q.push(tree[now].next[i]);
            }
        }
        return ;
    }
    int match(char *s) {
        int cnt = 0;
        int p = root, k;
        for (int i = 0; s[i]; i++) {
            // 状态转移
            int ind = s[i] - 'a';
            p = tree[p].next[ind];
            // 提取结果
            k = p;
            while (k) {
                cnt += tree[k].flag;
                tree[k].flag = 0;
                k = tree[k].fail;
            }
        }
        return cnt;
    }
private:
    int root;
};

char s[1000005];

int main() {
    int n;
    Automaton solve;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        solve.insert(s);
    }
    solve.build_ac();
    scanf("%s", s);
    auto ans = solve.match(s);
    printf("%d\n", ans);
    return 0;
}
