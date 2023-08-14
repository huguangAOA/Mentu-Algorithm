/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0, k = 0, num = 0;
        stack<TreeNode *> s;
        TreeNode *p;
        while (traversal[i]) {
            k = num = 0;
            while (traversal[i] == '-') i++, k++;
            while (traversal[i] != '-' && traversal[i]) num = num * 10 + traversal[i] - '0', i++;
            while (s.size() > k) s.pop();
            p = new TreeNode(num);
            if (s.size()) {
                if (s.top()->left == nullptr) s.top()->left = p;
                else s.top()->right = p;
            }
            s.push(p);
        }
        while (s.size()) p = s.top(), s.pop();
        return p;
    }
};