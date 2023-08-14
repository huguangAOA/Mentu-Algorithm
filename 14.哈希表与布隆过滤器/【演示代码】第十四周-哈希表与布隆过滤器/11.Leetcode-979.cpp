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
    int getResult(TreeNode *root, int &n, int &m) {
        n = m = 0;
        if (root == nullptr) return 0;
        n = 1, m = root->val;
        int ans = 0, n1, m1;
        ans += getResult(root->left, n1, m1);
        ans += abs(n1 - m1);
        n += n1, m += m1;
        ans += getResult(root->right, n1, m1);
        ans += abs(n1 - m1);
        n += n1, m += m1;
        return ans;
    }
    int distributeCoins(TreeNode* root) {
        int n, m;
        return getResult(root, n, m);
    }
};






