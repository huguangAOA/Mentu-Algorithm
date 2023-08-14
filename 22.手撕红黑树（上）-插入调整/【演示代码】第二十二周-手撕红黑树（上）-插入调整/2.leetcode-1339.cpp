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
    int avg, ans = 0;
    int getTotal(TreeNode *root) {
        if (root == nullptr) return 0;
        int val = root->val + getTotal(root->left) + getTotal(root->right);
        if (abs(val - avg) < abs(ans - avg)) ans = val;
        return val;
    }
    int maxProduct(TreeNode* root) {
        int total = getTotal(root);
        avg = total / 2;
        ans = total;
        getTotal(root);
        return (long long)(ans) * (total - ans) % (long long)(1e9+7);
    }
};