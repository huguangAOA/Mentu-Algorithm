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
    char buff[500000];
    void getPathString(TreeNode *root, int k, int a, int b, string &a_str, string &b_str, char *buff) {
        buff[k] = 0;
        if (root == nullptr) {
            return ;
        }
        if (root->val == a) a_str = buff;
        if (root->val == b) b_str = buff;
        buff[k] = 'L';
        getPathString(root->left,  k + 1, a, b, a_str, b_str, buff);
        buff[k] = 'R';
        getPathString(root->right, k + 1, a, b, a_str, b_str, buff);
        return ;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s_str, d_str;
        getPathString(root, 0, startValue, destValue, s_str, d_str, buff);
        int i = 0;
        while (s_str[i] && s_str[i] == d_str[i]) i += 1;
        s_str = s_str.substr(i, s_str.size());
        d_str = d_str.substr(i, d_str.size());
        for (i = 0; s_str[i]; i++) s_str[i] = 'U';
        return s_str + d_str;
    }
};