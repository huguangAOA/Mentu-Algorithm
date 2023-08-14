class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        multiset<int> s;
        for (auto x : sticks) s.insert(x);
        int ans = 0;
        while (s.size() - 1) {
            int a = *(s.begin()); s.erase(s.begin());
            int b = *(s.begin()); s.erase(s.begin());
            s.insert(a + b);
            ans += a + b;
        }
        return ans;
    }
};