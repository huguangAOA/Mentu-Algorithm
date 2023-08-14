class Solution {
public:
    struct Data {
        Data(int a, int b) : a(a), b(b) {
            int c = gcd(a, b);
            this->a /= c;
            this->b /= c;
        }
        bool operator<(const Data &obj) const {
            if (a - obj.a) return a < obj.a;
            return b < obj.b;
        }
        int a, b;
    };
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<Data, long long> h;
        long long ans = 0;
        for (auto x : rectangles) {
            Data d(x[0], x[1]);
            ans += h[d];
            h[d] += 1;
        }
        return ans;
    }
};