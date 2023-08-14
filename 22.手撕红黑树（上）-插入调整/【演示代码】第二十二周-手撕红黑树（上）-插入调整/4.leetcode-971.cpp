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
    int ind;
    bool preorder(TreeNode *root, vector<int> &voyage, vector<int> &ret) {
        if (root == nullptr) return true;
        if (voyage[ind] != root->val) {
            ret.clear();
            ret.push_back(-1);
            return false;
        }
        ind += 1;
        if (ind + 1 == voyage.size()) return true;
        if (root->left && root->left->val != voyage[ind]) {
            swap(root->left, root->right);
            ret.push_back(root->val);
        }
        if (!preorder(root->left, voyage, ret)) return false;
        if (!preorder(root->right, voyage, ret)) return false;
        return true;
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ret;
        ind = 0;
        preorder(root, voyage, ret);
        return ret;
    }
};