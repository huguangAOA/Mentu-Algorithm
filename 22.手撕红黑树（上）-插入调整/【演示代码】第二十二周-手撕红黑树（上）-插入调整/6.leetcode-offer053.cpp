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
    TreeNode *pre, *ans;
    bool inorder(TreeNode *root, TreeNode *p) {
        if (root == nullptr) return false;
        if (inorder(root->left, p)) return true;
        if (pre == p) {
            ans = root;
            return true;
        }
        pre = root;
        if (inorder(root->right, p)) return true;
        return false;
    } 
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        pre = ans = nullptr;
        inorder(root, p);
        return ans;
    }
};