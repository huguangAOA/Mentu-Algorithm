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
    unordered_map<int, int> h;
    int count(TreeNode *root, int sum, int targetSum) {
        if (root == nullptr) return 0;
        sum += root->val;
        int ans = h[sum - targetSum];
        h[sum] += 1;
        ans += count(root->left,  sum, targetSum);
        ans += count(root->right, sum ,targetSum);
        h[sum] -= 1;
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        h.clear();
        h[0] = 1;
        return count(root, 0, targetSum);
    }
};