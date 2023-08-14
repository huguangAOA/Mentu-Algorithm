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
    void mergeSequences(
        vector<int> &l, int lind, vector<int> &r, int rind, 
        vector<int> &buff, vector<vector<int>> &ret) {
        if (lind == l.size() && rind == r.size()) {
            ret.push_back(buff);
            return ;
        }
        if (lind < l.size()) {
            buff.push_back(l[lind]);
            mergeSequences(l, lind + 1, r, rind, buff, ret);
            buff.pop_back();
        }
        if (rind < r.size()) {
            buff.push_back(r[rind]);
            mergeSequences(l, lind, r, rind + 1, buff, ret);
            buff.pop_back();
        }
        return ;
    }
    vector<vector<int>> BSTSequences(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) {
            ret.push_back(vector<int>());
            return ret;
        }
        vector<vector<int>> l_arr = BSTSequences(root->left);
        vector<vector<int>> r_arr = BSTSequences(root->right);
        for (auto l : l_arr) {
            for (auto r : r_arr) {
                vector<int> buff;
                buff.push_back(root->val);
                mergeSequences(l, 0, r, 0, buff, ret);
            }
        }
        return ret;
    }
};