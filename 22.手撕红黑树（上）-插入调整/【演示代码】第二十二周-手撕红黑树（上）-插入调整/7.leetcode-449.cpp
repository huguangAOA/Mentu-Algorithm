/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        string ret = "";
        stringstream ss;
        ss << root->val;
        ss >> ret;
        if (root->left == nullptr && root->right == nullptr) return ret;
        ret += "(";
        ret += serialize(root->left);
        if (root->right) {
            ret += ",";
            ret += serialize(root->right);
        }
        ret += ")";
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int scode = 0, ind = 0, k = 0;
        stack<TreeNode *> s;
        TreeNode *p, *root = nullptr;
        while (ind < data.size()) {
            switch (scode) {
                case 0: {
                    if (data[ind] <= '9' && data[ind] >= '0') scode = 1;
                    else if (data[ind] == '(') scode = 2;
                    else if (data[ind] == ',') scode = 3;
                    else if (data[ind] == ')') scode = 4;
                } break;
                case 1: {
                    int num = 0;
                    while (ind < data.size() && data[ind] <= '9' && data[ind] >= '0') {
                        num = num * 10 + (data[ind] - '0');
                        ind += 1;
                    }
                    p = new TreeNode(num);
                    if (root == nullptr) root = p;
                    if (k == 1) s.top()->left = p;
                    else if (k == 2) s.top()->right = p;
                    scode = 0;
                } break;
                case 2: {
                    s.push(p);
                    ind += 1;
                    k = 1;
                    scode = 0;
                } break;
                case 3: {
                    k = 2;
                    ind += 1;
                    scode = 0;
                } break;
                case 4: {
                    s.pop();
                    ind += 1;
                    scode = 0;
                } break;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;