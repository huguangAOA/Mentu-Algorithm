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
    int nodeCount(TreeNode *root) {
        if (root == nullptr) return 0;
        return nodeCount(root->left) + nodeCount(root->right) + 1;
    }
    bool judge(TreeNode *root, int n, int m) {
        if (root == nullptr) return n == 0;
        if (n == 0) return false;
        if (n == 1) return root->left == nullptr && root->right == nullptr;
        int k = max(0, 2 * m - 1);
        int l = min(m, n - k), r = n - k - l;
        //cout << n << " : " << k << ", " << l << ", " << r << endl;
        return judge(root->left, (k - 1) / 2 + l, m / 2) && judge(root->right, (k - 1) / 2 + r, m / 2);
    }
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;
        int n = nodeCount(root), m = 1, cnt = 1;
        while (cnt + 2 * m <= n) {
            m *= 2;
            cnt += m;
        }
        return judge(root, n, m);
    }
};