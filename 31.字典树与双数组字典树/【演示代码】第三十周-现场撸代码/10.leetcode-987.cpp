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
    typedef pair<int, int> PII;
    map<int, vector<PII>> h;
    void getResult(TreeNode *root, int i, int j) {
        if (root == nullptr) return ;
        h[j].push_back(PII(i, root->val));
        getResult(root->left,  i + 1, j - 1);
        getResult(root->right, i + 1, j + 1);
        return ;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        h.clear();
        getResult(root, 0, 0);
        vector<vector<int>> ret;
        for (auto item : h) {
            vector<PII> &arr = item.second;
            sort(arr.begin(), arr.end());
            vector<int> temp;
            for (auto x : arr) temp.push_back(x.second);
            ret.push_back(temp);
        }
        return ret;
    }
};

