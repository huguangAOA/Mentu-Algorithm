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
    int max_k, val;
    void dfs(TreeNode *root, int k) {
        if (root == nullptr) return ;
        if (k > max_k) {
            max_k = k, val = root->val;
        }
        dfs(root->left, k + 1);
        dfs(root->right, k + 1);
        return ;
    }
    int findBottomLeftValue(TreeNode* root) {
        max_k = -1, val = 0;
        dfs(root, 0);
        return val;
    }
};