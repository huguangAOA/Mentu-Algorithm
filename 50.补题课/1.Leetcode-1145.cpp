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
    TreeNode *find(TreeNode *root, int x) {
        if (root == nullptr) return nullptr;
        if (root->val == x) return root;
        TreeNode *p;
        if ((p = find(root->left, x))) return p;
        if ((p = find(root->right, x))) return p;
        return nullptr;
    }
    int getCnt(TreeNode *root) {
        if (root == nullptr) return 0;
        return getCnt(root->left) + getCnt(root->right) + 1;
    } 

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode *p = find(root, x);
        int lcnt = getCnt(p->left);
        int rcnt = getCnt(p->right);
        int fcnt = n - lcnt - rcnt - 1;
        return lcnt * 2 > n || rcnt * 2 > n || fcnt * 2 > n; 
    }
};