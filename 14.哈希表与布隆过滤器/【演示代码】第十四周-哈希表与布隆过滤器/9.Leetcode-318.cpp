class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mark(words.size());
        for (int i = 0; i < words.size(); i++) {
            for (auto c : words[i]) {
                mark[i] |= (1 << (c - 'a'));
            }
        }
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (mark[i] & mark[j]) continue;
                ans = max(ans, int(words[i].size() * words[j].size()));
            }
        }
        return ans;
    }
};