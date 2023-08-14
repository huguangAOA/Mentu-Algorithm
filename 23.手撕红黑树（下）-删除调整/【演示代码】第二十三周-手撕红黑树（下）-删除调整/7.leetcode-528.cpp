class Solution {
public:
    int n;
    vector<int> sum;
    Solution(vector<int>& w) : sum(w) {
        for (int i = 1; i < sum.size(); i++) sum[i] += sum[i - 1];
        n = sum[sum.size() - 1];
    }
    
    int pickIndex() {
        int x = rand() % n;
        int head = 0, tail = sum.size() - 1;
        while (head < tail) {
            int mid = (head + tail) >> 1;
            if (sum[mid] <= x) head = mid + 1;
            else tail = mid;
        }
        return head;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */