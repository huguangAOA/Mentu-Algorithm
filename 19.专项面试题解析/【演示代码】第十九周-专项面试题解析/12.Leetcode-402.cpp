class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0";
        string ret;
        for (auto x : num) {
            while (k && ret.size() && ret.back() > x) ret.pop_back(), k -= 1;
            ret.push_back(x);
        }
        if (k != 0) ret = ret.substr(0, ret.size() - k);
        int ind = 0;
        while (ret[ind] == '0') ++ind;
        ret = ret.substr(ind, ret.size());
        if (ret == "") ret = "0";
        return ret;
    }
};