class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> l(ratings.size()), r(ratings.size());
        for (int i = 0, j = 1; i < l.size(); i++) {
            if (i && ratings[i] > ratings[i - 1]) j += 1;
            else j = 1;
            l[i] = j;
        }
        for (int i = r.size() - 1, j = 1; i >= 0; i--) {
            if (i < r.size() - 1 && ratings[i] > ratings[i + 1]) j += 1;
            else j = 1;
            r[i] = j;
        }
        int ans = 0;
        for (int i = 0; i < l.size(); i++) ans += max(l[i], r[i]);
        return ans;
    }
};