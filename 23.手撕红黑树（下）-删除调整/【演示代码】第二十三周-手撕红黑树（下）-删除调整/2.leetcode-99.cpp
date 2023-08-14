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
    TreeNode *pre, *p, *q;
    void inorder(TreeNode *root) {
        if (root == nullptr) return ;
        inorder(root->left);
        if (pre && root->val < pre->val) {
            if (p == nullptr) p = pre;
            q = root;
        }
        pre = root;
        inorder(root->right);
        return ;
    }
    void recoverTree(TreeNode* root) {
        pre = p = q = nullptr;
        inorder(root);
        swap(p->val, q->val);
        return ;
    }
};