class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<queue<int>> pos(10);
        for (int i = 0; s[i]; i++) pos[s[i] - '0'].push(i);
        for (int i = 0; t[i]; i++) {
            if (pos[t[i] - '0'].empty()) return false;
            int p = pos[t[i] - '0'].front();
            for (int j = 0, J = t[i] - '0'; j < J; j++) {
                if (!pos[j].empty() && pos[j].front() < p) return false;
            }
            pos[t[i] - '0'].pop();
        }
        return true;
    }
};