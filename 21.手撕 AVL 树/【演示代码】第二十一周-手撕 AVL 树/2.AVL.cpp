/*************************************************************************
	> File Name: 2.AVL.cpp
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

#define NIL (&node::__NIL)

struct node {
    node(int key = 0, int h = 0, node *left = NIL, node *right = NIL)
    : key(key), left(left), right(right), h(h) {}
    int key, h;
    node *left, *right;
    static node __NIL;
};

node node::__NIL;

node *getNewNode(int key) {
    return new node(key, 1);
}

void update_height(node *root) {
    root->h = max(root->left->h, root->right->h) + 1;
    return ;
}

node *left_rotate(node *root) {
    node *new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    update_height(root);
    update_height(new_root);
    return new_root;
}

node *right_rotate(node *root) {
    node *new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
    update_height(root);
    update_height(new_root);
    return new_root;
}

const char *TYPE_STR[5] = {"", "LL","RR","LR","RL"};

node *maintain(node *root) {
    if (abs(root->left->h - root->right->h) < 2) return root;
    int type = -1, val = root->key;
    if (root->left->h > root->right->h) {
        if (root->left->right->h > root->left->left->h) {
            printf("%d : left rotate\n", root->left->key);
            root->left = left_rotate(root->left);
            type = 3;
        }
        printf("%d : right rotate\n", root->key);
        root = right_rotate(root);
        if (type == -1) type = 1;
    } else {
        if (root->right->left->h > root->right->right->h) {
            printf("%d : right rotate\n", root->right->key);
            root->right = right_rotate(root->right);
            type = 4;
        }
        printf("%d : left rotate\n", root->key);
        root = left_rotate(root);
        if (type == -1) type = 4;
    }
    printf("maintain type = %s\n", TYPE_STR[type]);
    return root;
}

node *insert(node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    update_height(root);
    return maintain(root);
}

node *predeccessor(node *root) {
    node *temp = root->left;
    while (temp->right != NIL) temp = temp->right;
    return temp;
}

node *erase(node *root, int key) {
    if (root == NIL) return root;
    if (key < root->key) {
        root->left = erase(root->left, key);
    } else if (key > root->key) {
        root->right = erase(root->right, key);
    } else {
        if (root->left == NIL || root->right == NIL) {
            node *temp = (root->left == NIL ? root->right : root->left);
            delete root;
            return temp;
        } else {
            node *temp = predeccessor(root);
            root->key = temp->key;
            root->left = erase(root->left, temp->key);
        }
    }
    update_height(root);
    return maintain(root);
}

void clear(node *root) {
    if (root == NIL) return ;
    clear(root->left);
    clear(root->right);
    cout << "delete : " << root->key << endl;
    delete root;
    return ;
}

void print(node *root) {
    printf("( %d[%d] | %d, %d )\n", root->key, root->h, root->left->key, root->right->key);
    return ;
}

void output(node *root) {
    if (root == NIL) return ;
    print(root);
    output(root->left);
    output(root->right);
    return ;
}

int main() {
    int op, val;
    node *root = NIL;
    while (cin >> op >> val) {
        cout << endl << "==== AVL tree print ====" << endl;
        switch (op) {
            case 0: root = insert(root, val); break;
            case 1: root = erase(root, val); break;
        }
        output(root);
        cout << "==== tree print done ====" << endl;
    }
    clear(root);
    return 0;
}
