class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size());
        stack<int> s;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (s.size() && temperatures[i] > temperatures[s.top()]) {
                ret[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ret;
    }
};