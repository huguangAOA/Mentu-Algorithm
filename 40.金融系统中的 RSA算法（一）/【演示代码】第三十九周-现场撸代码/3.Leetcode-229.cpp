class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        pair<int, int> a(0, 0), b(0, 0);
        for (auto x : nums) {
            if (a.second && a.first == x) a.second += 1;
            else if (b.second && b.first == x) b.second += 1;
            else if (a.second == 0) a.first = x, a.second = 1;
            else if (b.second == 0) b.first = x, b.second = 1;
            else {
                a.second -= 1;
                b.second -= 1;
            }
        }
        cout << a.first << " " << b.first << endl;
        a.second = b.second = 0;
        for (auto x : nums) {
            if (x == a.first) a.second += 1;
            else if (x == b.first) b.second += 1;
        }
        vector<int> ret;
        if (a.second * 3 > nums.size()) ret.push_back(a.first);
        if (b.second * 3 > nums.size()) ret.push_back(b.first);
        return ret;
    }
};