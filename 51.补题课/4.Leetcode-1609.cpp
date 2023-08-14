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
    bool dfs(TreeNode *root, int k, vector<int> &buff) {
        if (root == nullptr) return true;
        bool first = false;
        if (k >= buff.size()) buff.push_back(root->val), first = true;
        if (k % 2) {
            if (root->val % 2 == 1) return false;
            if (!first && root->val >= buff[k]) return false;
        } else {
            if (root->val % 2 == 0) return false;
            if (!first && root->val <= buff[k]) return false;
        }
        buff[k] = root->val;
        if (!dfs(root->left, k + 1, buff)) return false;
        if (!dfs(root->right, k + 1, buff)) return false;
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        vector<int> buff;
        return dfs(root, 0, buff);
    }
};