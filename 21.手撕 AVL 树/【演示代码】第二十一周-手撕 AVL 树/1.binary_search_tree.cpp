/*************************************************************************
	> File Name: 1.binary_search_tree.cpp
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

struct Node {
    Node(int key = 0, Node *left = nullptr, Node *right = nullptr)
    : key(key), left(left), right(right) {}
    int key;
    Node *left, *right;
};

Node *getNewNode(int key) {
    return new Node(key);
}

Node *insert(Node *root, int key) {
    if (root == nullptr) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

Node *predeccessor(Node *root) {
    Node *temp = root->left;
    while (temp->right) temp = temp->right;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == nullptr) return root;
    if (key < root->key) {
        root->left = erase(root->left, key);
    } else if (key > root->key) {
        root->right = erase(root->right, key);
    } else {
        if (root->left == nullptr || root->right == nullptr) {
            Node *temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        } else {
            Node *temp = predeccessor(root);
            root->key = temp->key;
            root->left = erase(root->left, temp->key);
        }
    }
    return root;
}

void clear(Node *root) {
    if (root == nullptr) return ;
    clear(root->left);
    clear(root->right);
    cout << "delete : " << root->key << endl;
    delete root;
    return ;
}

void output(Node *root) {
    if (root == nullptr) return ;
    output(root->left);
    cout << root->key << " ";
    output(root->right);
    return ;
}

int main() {
    int op, val;
    Node *root = nullptr;
    while (cin >> op >> val) {
        switch (op) {
            case 0: root = insert(root, val); break;
            case 1: root = erase(root, val); break;
        }
        output(root); cout << endl;
    }
    clear(root);
    return 0;
}
