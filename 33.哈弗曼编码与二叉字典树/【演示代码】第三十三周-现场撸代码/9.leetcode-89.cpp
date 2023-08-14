class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1 << n);
        if (n == 0) {
            ret[0] = 0;
            return ret;
        }
        vector<int> code_n_1 = grayCode(n - 1);
        int len_n_1 = code_n_1.size();
        for (int i = 0; i < len_n_1; i++) {
            ret[i] = code_n_1[i] << 1;
            ret[2 * len_n_1 - i - 1] = code_n_1[i] << 1 | 1;
        }
        return ret;
    }
};