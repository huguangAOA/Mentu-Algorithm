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
    vector<TreeNode*> dfs(int l, int r) {
        vector<TreeNode*> ans;
        if(l > r) {
            ans.push_back(nullptr);
            return ans;
        }

        for(int i = l; i <= r; i++) {
            vector<TreeNode*> left_tree = dfs(l, i - 1);
            vector<TreeNode*> right_tree = dfs(i + 1, r);
            //eg : i = 3
            for(TreeNode* left : left_tree) { // 遍历left_tree {1, null, 2}, {2, 1, null}
                for(TreeNode* right : right_tree) { // {4}
                    TreeNode* t = new TreeNode(i, left, right);
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n == 0) return ans;
        return dfs(1, n);
    }
};