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
    TreeNode *pre;
    bool inorder(TreeNode *root) {
        if (root == nullptr) return true;
        if (!inorder(root->left)) return false;
        if (pre != nullptr && root->val <= pre->val) {
            return false;
        }
        pre = root;
        if (!inorder(root->right)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        pre = nullptr;
        return inorder(root);
    }
};