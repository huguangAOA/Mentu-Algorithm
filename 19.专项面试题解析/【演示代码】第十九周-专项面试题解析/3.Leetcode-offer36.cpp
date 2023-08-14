/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *head, *pre;
    void in_order(Node *root) {
        if (root == nullptr) return ;
        in_order(root->left);
        // do something
        if (pre == nullptr) {
            head = root;
        } else {
            pre->right = root;
        }
        root->left = pre;
        pre = root;
        in_order(root->right);
        return ;
    }
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        head = pre = nullptr;
        in_order(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};