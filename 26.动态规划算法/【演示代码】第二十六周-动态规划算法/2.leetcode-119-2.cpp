class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> f(rowIndex + 1);
        int n = f.size();
        f[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            f[i] = 1;
            for (int j = i + 1; j < n - 1; j++) {
                f[j] += f[j + 1];
            }
        }
        return f;
    }
};