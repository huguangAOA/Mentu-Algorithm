class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<int> ind(n);
        for (int i = 0; i < n; i++) ind[i] = i;
        sort(ind.begin(), ind.end(), [&](int i, int j) -> bool { return capital[i] < capital[j]; });
        priority_queue<int> q;
        int i = 0;
        while (k--) {
            while (i < n && capital[ind[i]] <= w) q.push(profits[ind[i]]), i += 1;
            if (q.empty()) break;
            w += q.top();
            q.pop();
        }
        return w;
    }
};