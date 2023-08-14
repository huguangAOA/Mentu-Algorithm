class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ret;
        if (finalSum % 2 == 1) return ret;
        for (int i = 2; i <= finalSum; i += 2) {
            ret.push_back(i);
            finalSum -= i;
        }
        ret[ret.size() - 1] += finalSum;
        return ret;
    }
};