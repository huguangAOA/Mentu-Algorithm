/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *p = head, *q, *k;
        while (p) {
            if (p->child) {
                q = p->next;
                k = flatten(p->child);
                p->child = nullptr;
                p->next = k;
                k->prev = p;
                while (p->next) p = p->next;
                p->next = q;
                if (q) q->prev = p;
            }
            p = p->next;
        }
        return head;
    }
};