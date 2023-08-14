/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *layer_connect(Node *head) {
        Node *p = head, *pre = nullptr, *new_head = nullptr;
        while (p) {
            if (p->left) {
                if (pre) pre->next = p->left;
                pre = p->left;
            }
            if (new_head == nullptr) new_head = pre;
            if (p->right) {
                if (pre) pre->next = p->right;
                pre = p->right;
            }
            if (new_head == nullptr) new_head = pre;
            p = p->next;
        }
        return new_head;
    }
    Node* connect(Node* root) {
        Node *p = root;
        while (p = layer_connect(p)) ;
        return root;
    }
};