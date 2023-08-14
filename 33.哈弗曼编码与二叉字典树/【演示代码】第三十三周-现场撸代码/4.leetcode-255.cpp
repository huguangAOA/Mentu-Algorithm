class Solution {
public:
    int pre_ind;
    bool judge(vector<int> &preorder, int l, int r) {
        if (r - l < 1) return true;
        int ind = l + 1;
        while (ind < r && preorder[ind] < preorder[l]) ind += 1;
        if (!judge(preorder, l + 1, ind)) return false;
        if (pre_ind != -1 && preorder[l] < preorder[pre_ind]) return false;
        pre_ind = l;
        if (!judge(preorder, ind, r)) return false;
        return true;
    }
    bool verifyPreorder(vector<int>& preorder) {
        pre_ind = -1;
        return judge(preorder, 0, preorder.size());
    }
};