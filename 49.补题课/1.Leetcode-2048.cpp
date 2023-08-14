class Solution {
public:
    void getNumber(int d, int ind, vector<int>& buff, vector<int>& arr) {
        if (d == 0) {
            vector<int> temp;
            for (auto x : buff) for (int i = 0; i < x; i++) temp.push_back(x);
            do {
                int num = 0;
                for (auto x : temp) num = num * 10 + x;
                arr.push_back(num);
            } while (next_permutation(temp.begin(), temp.end()));
            return ;
        }
        for (int i = ind; i <= d; i++) {
            if (d - i > i || i == d) {
                buff.push_back(i);
                getNumber(d - i, i + 1, buff, arr);
                buff.pop_back();
            }
        }
        return ;
    }
    void getAllNumber(int d, vector<int>& arr) {
        vector<int> buff;
        getNumber(d, 1, buff, arr);
        return ;
    }
    int nextBeautifulNumber(int n) {
        if (n == 0) return 1;
        int d = floor(log10(n)) + 1;
        vector<int> arr;
        getAllNumber(d, arr);
        getAllNumber(d + 1, arr);
        int ans = INT_MAX;
        for (auto x : arr) {
            if (x > n) ans = min(ans, x);
        }
        return ans;
    }
};