class Solution {
public:
    int pre;
    bool inorder(vector<int> &nums, int l, int r) {
        if (l > r) return true;
        int ind = l;
        while (nums[ind] < nums[r]) ++ind;
        if (!inorder(nums, l, ind - 1)) return false;
        if (pre != -1 && nums[r] <= nums[pre]) return false;
        pre = r;
        if (!inorder(nums, ind, r - 1)) return false;
        return true;
    }
    bool verifyPostorder(vector<int>& postorder) {
        pre = -1;
        return inorder(postorder, 0, postorder.size() - 1);
    }
};