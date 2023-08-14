/*************************************************************************
	> File Name: 1.red_black_tree.cpp
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

#define NIL &(node::__NIL)
struct node {
    node(int key = 0, int color = 0, node *lchild = NIL, node *rchild = NIL)
    : key(key), color(color), lchild(lchild), rchild(rchild) {}
    int key;
    int color; // 0 red, 1 black, 2 double black
    node *lchild, *rchild;
    static node __NIL;
};

node node::__NIL(0, 1);

node *getNewNode(int key) {
    return new node(key);
}

bool has_red_child(node *root) {
    return root->lchild->color == 0 || root->rchild->color == 0;
}

node *left_rotate(node *root) {
    node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

node *right_rotate(node *root) {
    node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

node *insert_maintain(node *root) {
    int flag = 0;
    if (root->lchild->color == 0 && has_red_child(root->lchild)) flag = 1;
    if (root->rchild->color == 0 && has_red_child(root->rchild)) flag = 2;
    if (flag == 0) return root;
    if (root->lchild->color == 0 && root->rchild->color == 0) {
        root->color = 0;
        root->lchild->color = root->rchild->color = 1;
        return root;
    }
    if (flag == 1) {
        if (root->lchild->rchild->color == 0) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (root->rchild->lchild->color == 0) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    root->color = 0;
    root->lchild->color = root->rchild->color = 1;
    return root;
}

node *__insert(node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (key == root->key) return root;
    if (key < root->key) {
        root->lchild = __insert(root->lchild, key);
    } else {
        root->rchild = __insert(root->rchild, key);
    }
    return insert_maintain(root);
}

node *insert(node *root, int key) {
    root = __insert(root, key);
    root->color = 1;
    return root;
}

void clear(node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    delete root;
    return ;
}

void print(node *root) {
    printf("( %d | %d, %d, %d )\n", 
        root->color, root->key, 
        root->lchild->key, root->rchild->key
    );
    return ;
}

void output(node *root) {
    if (root == NIL) return ;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    int val;
    node *root = NIL;
    while (cin >> val) {
        root = insert(root, val);
        cout << endl << "==== rbtree print ====" << endl;
        output(root);
        cout << "==== rbtree print done ====" << endl;
    }
    return 0;
}
