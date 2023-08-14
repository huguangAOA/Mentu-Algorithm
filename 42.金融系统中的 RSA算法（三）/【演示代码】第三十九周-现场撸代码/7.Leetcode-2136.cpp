class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int ans = INT_MIN, n = plantTime.size();
        vector<int> ind(n);
        for (int i = 0; i < n; i++) ind[i] = i;
        sort(ind.begin(), ind.end(), [&](int i, int j) -> bool { return growTime[i] > growTime[j]; });
        for (int i = 0, sum = 0; i < n; i++) {
            sum += plantTime[ind[i]];
            ans = max(ans, sum + growTime[ind[i]]);
        }
        return ans;
    }
};