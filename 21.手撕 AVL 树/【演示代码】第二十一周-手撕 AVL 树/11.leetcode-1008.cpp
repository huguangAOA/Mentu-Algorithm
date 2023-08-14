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
    TreeNode *buildTree(vector<int> &nums, int l, int r) {
        if (l > r) return nullptr;
        int ind = l + 1;
        while (ind <= r && nums[ind] < nums[l]) ++ind;
        TreeNode *root = new TreeNode(nums[l]);
        root->left = buildTree(nums, l + 1, ind - 1);
        root->right = buildTree(nums, ind, r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildTree(preorder, 0, preorder.size() - 1);
    }
};