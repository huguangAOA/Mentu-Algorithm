class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> h;
        for (int i = 0, I = s.size() - 9; i < I; i++) {
            h[s.substr(i, 10)] += 1;
        }
        vector<string> ret;
        for (auto x : h) {
            if (x.second == 1) continue;
            ret.push_back(x.first);
        }
        return ret;
    }
};