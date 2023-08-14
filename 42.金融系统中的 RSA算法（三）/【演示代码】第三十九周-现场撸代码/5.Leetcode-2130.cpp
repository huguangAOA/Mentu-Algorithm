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
    ListNode *node;
    int getMaxValue(ListNode *head, ListNode *q) {
        if (q == nullptr) {
            node = head;
            return INT_MIN;
        }
        int ans = getMaxValue(head, q->next);
        ans = max(ans, node->val + q->val);
        node = node->next;
        return ans;
    }
    int pairSum(ListNode* head) {
        ListNode *p = head, *q = head;
        while (p) {
            p = p->next->next;
            q = q->next;
        }
        return getMaxValue(head, q);
    }
};