class Solution {
public:
    int gcd(int a, int b) {
        if (!b) return a;
        return gcd(b, a % b);
    }
    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        for (auto x : nums) {
            while (s.size() && gcd(x, s.top()) != 1) {
                x = lcm(x, s.top());
                s.pop();
            }
            s.push(x);
        }
        vector<int> ret(s.size());
        for (int i = ret.size() - 1; i >= 0; i--) {
            ret[i] = s.top();
            s.pop();
        }
        return ret;
    }
};