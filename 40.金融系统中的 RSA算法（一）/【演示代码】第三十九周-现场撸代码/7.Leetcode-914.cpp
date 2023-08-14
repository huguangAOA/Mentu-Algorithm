class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> h;
        for (auto x : deck) h[x] += 1;
        int x = -1;
        for (auto d : h) {
            if (x == -1) x = d.second;
            else x = gcd(x, d.second);
            if (x == 1) break;
        }
        return x > 1;
    }
};