class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        for (int i = 1; i < n; i++) arr[i] ^= arr[i - 1];
        vector<int> ret(queries.size());
        for (int i = 0, m = queries.size(); i < m; i++) {
            ret[i] = arr[queries[i][1]] ^ (queries[i][0] ? arr[queries[i][0] - 1] : 0);
        }
        return ret;
    }
};