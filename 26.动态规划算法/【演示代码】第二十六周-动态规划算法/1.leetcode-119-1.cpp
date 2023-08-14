class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> f;
        for (int i = 0; i < 2; i++) f.push_back(vector<int>(rowIndex + 1));
        f[0][0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            int pre_ind = (i - 1) % 2, ind = i % 2;
            f[ind][0] = 1;
            for (int j = 1; j <= i; j++) {
                f[ind][j] = f[pre_ind][j - 1] + f[pre_ind][j];
            }
        }
        return f[rowIndex % 2];
    }
};