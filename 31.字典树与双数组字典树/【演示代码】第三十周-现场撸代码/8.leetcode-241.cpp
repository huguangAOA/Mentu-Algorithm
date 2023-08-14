class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ret;
        for (int i = 0; expression[i]; i++) {
            char op = expression[i];
            if (op != '+' && op != '-' && op != '*') continue;
            string a_str = expression.substr(0, i);
            string b_str = expression.substr(i + 1, expression.size());
            vector<int> a = diffWaysToCompute(a_str);
            vector<int> b = diffWaysToCompute(b_str);
            for (auto x : a) {
                for (auto y : b) {
                    switch (op) {
                        case '+': ret.push_back(x + y); break;
                        case '-': ret.push_back(x - y); break;
                        case '*': ret.push_back(x * y); break;
                    }
                }
            }
        }
        if (ret.size() == 0) {
            int num = 0;
            for (auto x : expression) {
                num = num * 10 + (x - '0');
            }
            ret.push_back(num);
        }
        return ret;
    }
};