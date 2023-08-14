class Solution {
public:
    typedef pair<int, int> PII;
    PII getNext(int k, int x, int X, int y, int Y) {
        switch (k) {
            case 0: return PII(0, y);
            case 1: return PII(x, 0);
            case 2: {
                int delta = min(x, Y - y);
                return PII(x - delta, y + delta);
            }
            case 3: {
                int delta = min(X - x, y);
                return PII(x + delta, y - delta);
            }
            case 4: return PII(X, y);
            case 5: return PII(x, Y);
        }
        return PII(0, 0);
    }
    struct HASH {
        long long operator()(const PII &a) const {
            return ((long long)(a.first) << 31) + a.second;
        }
    };
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        unordered_set<PII, HASH> vis;
        queue<PII> q;
        vis.insert(PII(0, 0));
        q.push(PII(0, 0));
        while (!q.empty()) {
            PII cur = q.front();
            if (cur.first + cur.second == targetCapacity) return true;
            q.pop();
            for (int i = 0; i < 6; i++) {
                PII temp = getNext(i, cur.first, jug1Capacity, cur.second, jug2Capacity);
                if (vis.find(temp) != vis.end()) continue;
                vis.insert(temp);
                q.push(temp);
            }
        }
        return false;
    }
};



