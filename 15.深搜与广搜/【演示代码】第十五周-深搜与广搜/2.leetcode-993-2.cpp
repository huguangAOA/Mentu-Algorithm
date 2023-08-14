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
    struct Data {
        Data(TreeNode *node = nullptr, TreeNode *father = nullptr, int deepth = 0) 
        : node(node), father(father), deepth(deepth) {}
        TreeNode *node, *father;
        int deepth;
    };
    bool isCousins(TreeNode* root, int x, int y) {
        int d1 = -1, d2 = -1;
        TreeNode *father_x = nullptr, *father_y = nullptr;
        queue<Data> q;
        q.push(Data(root, nullptr, 0));
        while (!q.empty()) {
            Data cur = q.front();
            if (cur.node->val == x) d1 = cur.deepth, father_x = cur.father;
            if (cur.node->val == y) d2 = cur.deepth, father_y = cur.father;
            if (cur.node->left) {
                q.push(Data(cur.node->left, cur.node, cur.deepth + 1));
            }
            if (cur.node->right) {
                q.push(Data(cur.node->right, cur.node, cur.deepth + 1));
            }
            q.pop();
        }
        return d1 == d2 && father_x != father_y;
    }
};
