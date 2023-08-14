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
    void inorder(TreeNode *root, vector<int> &ret) {
        if (root == nullptr) return ;
        inorder(root->left, ret);
        ret.push_back(root->val);
        inorder(root->right, ret);
        return ;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ret;
        inorder(root, ret);
        int p = 0, q = ret.size() - 1;
        while (p < q && ret[p] + ret[q] - k) {
            if (ret[p] + ret[q] < k) p += 1;
            else q -= 1;
        }
        return p < q;
    }
};