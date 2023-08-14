/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *pre;
    TreeNode *inorder(TreeNode *root, TreeNode *p) {
        if (root == nullptr) return nullptr;
        TreeNode *node;
        if (node = inorder(root->left, p)) return node;
        if (pre == p) return root;
        pre = root;
        if (node = inorder(root->right, p)) return node;
        return nullptr;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        pre = nullptr;
        return inorder(root, p);
    }
};