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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode *> node;
        unordered_map<int, int> indeg;
        for (auto x : descriptions) {
            if (node.find(x[0]) == node.end()) node[x[0]] = new TreeNode(x[0]);
            if (node.find(x[1]) == node.end()) node[x[1]] = new TreeNode(x[1]); 
            if (x[2] == 1) node[x[0]]->left = node[x[1]];
            else node[x[0]]->right = node[x[1]];
            indeg[x[1]] += 1;
        }
        for (auto x : node) {
            if (indeg[x.first]) continue;
            return x.second;
        }
        return nullptr;
    }
};