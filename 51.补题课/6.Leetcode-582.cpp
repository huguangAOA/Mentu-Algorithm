class Solution {
public:
    void getMark(unordered_map<int, vector<int>>& g, int ind, vector<int>& mark) {
        mark.push_back(ind);
        for (auto x : g[ind]) getMark(g, x, mark);
        return ;
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        unordered_map<int, vector<int>> g;
        vector<int> mark;
        for (int i = 0; i < n; i++) g[ppid[i]].push_back(pid[i]);
        getMark(g, kill, mark);
        return mark;
    }
};