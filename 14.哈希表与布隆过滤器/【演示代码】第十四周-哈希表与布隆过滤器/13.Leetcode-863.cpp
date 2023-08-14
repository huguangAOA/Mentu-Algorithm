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
    void dfs(TreeNode *root, int c, int k, vector<int> &ret) {
        if (k < 0) return ;
        if (root == nullptr) return ;
        if (c == k) {
            ret.push_back(root->val);
            return ;
        }
        dfs(root->left,  c + 1, k, ret);
        dfs(root->right, c + 1, k, ret);
        return ;
    }
    TreeNode *getResult(TreeNode *root, TreeNode *target, int &k, vector<int> &ret) {
        if (root == nullptr) return nullptr;
        if (root == target) {
            dfs(root, 0, k, ret);
            return root;
        }
        if (getResult(root->left, target, k, ret)) {
            k -= 1;
            if (k == 0) ret.push_back(root->val);
            dfs(root->right, 0, k - 1, ret);
            return target;
        } else if (getResult(root->right, target, k, ret)) {
            k -= 1;
            if (k == 0) ret.push_back(root->val);
            dfs(root->left, 0, k - 1, ret);
            return target;
        }
        return nullptr;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ret;
        getResult(root, target, k, ret);
        return ret;
    };
};