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
    TreeNode *predeccessor(TreeNode *root) {
        TreeNode *temp = root->left;
        while (temp->right) temp = temp->right;
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr || root->right == nullptr) {
                TreeNode *temp = (root->left ? root->left : root->right);
                //delete root;
                return temp;
            } else {
                TreeNode *temp = predeccessor(root);
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        }
        return root;
    }
};