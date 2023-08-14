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
    void getNodes(TreeNode *root, vector<TreeNode *> &nodes) {
        if (root == nullptr) return ;
        getNodes(root->left, nodes);
        nodes.push_back(root);
        getNodes(root->right, nodes);
        return ;
    }
    TreeNode *buildTree(vector<TreeNode *> &nodes, int l, int r) {
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        TreeNode *root = nodes[mid];
        root->left = buildTree(nodes, l, mid - 1);
        root->right = buildTree(nodes, mid + 1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *> nodes;
        getNodes(root, nodes);
        return buildTree(nodes, 0, nodes.size() - 1);
    }
};