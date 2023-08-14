/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *p = head, *max_node = head;
        while (p) {
            if (p->val > p->next->val) max_node = p;
            if (p->val <= insertVal && p->next->val >= insertVal) break;
            if (head == p->next) { p = max_node; break; }
            p = p->next;
        }
        if (p) {
            p->next = new Node(insertVal, p->next);
        }
        if (!head) {
            head = new Node(insertVal);
            head->next = head;
        }
        return head;
    }
};