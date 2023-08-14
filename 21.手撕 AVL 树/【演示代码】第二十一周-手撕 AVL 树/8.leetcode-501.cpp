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
    int cnt, max_cnt;
    TreeNode *now;
    void getResult(TreeNode *root, vector<int> &ret) {
        if (root == nullptr) return ;
        getResult(root->left, ret);
        if (now->val == root->val) {
            cnt += 1;
        } else {
            now = root;
            cnt = 1;
        }
        if (cnt == max_cnt) {
            ret.push_back(now->val);
        } else if (cnt > max_cnt) {
            max_cnt = cnt;
            ret.clear();
            ret.push_back(now->val);
        }
        getResult(root->right, ret);
        return ;
    }
    vector<int> findMode(TreeNode* root) {
        cnt = max_cnt = 0;
        now = root;
        vector<int> ret;
        getResult(root, ret);
        return ret;
    }
};