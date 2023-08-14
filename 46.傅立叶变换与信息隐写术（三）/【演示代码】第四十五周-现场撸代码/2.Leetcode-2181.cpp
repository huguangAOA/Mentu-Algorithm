/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if (head->next == nullptr) return nullptr;
        ListNode *p = head;
        while (p->next->val != 0) {
            p->val += p->next->val;
            p->next = p->next->next;
        }
        p->next = mergeNodes(p->next);
        return head;
    }
};