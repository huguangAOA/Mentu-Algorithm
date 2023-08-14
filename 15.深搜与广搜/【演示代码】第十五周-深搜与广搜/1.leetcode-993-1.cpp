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
    int dfs(TreeNode *root, int x, TreeNode *&father) {
        if (root == nullptr) return -1;
        if (root->val == x) return 0;
        int l;
        father = root;
        l = dfs(root->left, x, father);
        if (l != -1) return l + 1;
        father = root;
        l = dfs(root->right, x, father);
        if (l != -1) return l + 1;
        return -1;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int d1, d2;
        TreeNode *father_x = nullptr, *father_y = nullptr;
        d1 = dfs(root, x, father_x);
        d2 = dfs(root, y, father_y);
        return d1 == d2 && father_x != father_y;
    }
};
