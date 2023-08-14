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
    TreeNode *head, *pre;
    void inorder(TreeNode *root) {
        if (root == nullptr) return ;
        inorder(root->left);
        if (pre == nullptr) {
            head = root;
        } else {
            pre->right = root;
        }
        root->left = nullptr;
        pre = root;
        inorder(root->right);
        return ;
    }
    TreeNode* convertBiNode(TreeNode* root) {
        head = pre = nullptr;
        inorder(root);
        return head;
    }
};