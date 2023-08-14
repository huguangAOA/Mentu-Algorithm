class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<int> ind(n);
        for (int i = 0; i < n; i++) ind[i] = i;
        sort(ind.begin(), ind.end(), [&](int i, int j) -> bool {
            if (arr[i] - arr[j]) return arr[i] < arr[j];
            return i < j;
        });
        vector<long long> ret(n);
        for (int i = 0, j; i < n; i = j + 1) {
            j = i;
            while (j + 1 < n && arr[ind[j + 1]] == arr[ind[i]]) ++j;
            cout << arr[ind[i]] << " " << i << " " << j << endl;
            long long sum_pre = 0, sum_next = 0;
            for (int k = i; k <= j; k++) sum_next += ind[k];
            for (int k = i; k <= j; k++) {
                sum_next -= ind[k];
                ret[ind[k]] = (long long)(2 * k - i - j) * ind[k] - sum_pre + sum_next;
                sum_pre += ind[k];
            }
        }
        return ret;
    }
};