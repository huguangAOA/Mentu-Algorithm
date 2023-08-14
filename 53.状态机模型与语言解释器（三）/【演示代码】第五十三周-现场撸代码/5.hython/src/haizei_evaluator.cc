#include <haizei_evaluator.h>
#include <iostream>

int demoEvaluator::run(ASTree tree) {
    if (tree.type() == -1) {
        int r = 0;
        for(int i = 0; i < tree.size(); i++) {
            r = run(tree[i]);
        }
        return r;
    }
    switch(tree.type()) {
        case INT: {
            std::string s = tree.str();
            if (s[0] == '~') {
                return -atoi(s.c_str() + 1);
            } else {
                return atoi(s.c_str());
            }
        }
        case ID: {
            return memory[tree.str()];
        }
        case PLUS : return run(tree[0]) + run(tree[1]);
        case MINUS: return run(tree[0]) - run(tree[1]);
        case TIMES: return run(tree[0]) * run(tree[1]);
        case ASSIGN: {
            std::string var = tree[0].str();
            int val = run(tree[1]);
            memory[var] = val;
            std::cout << var << " = " << val << std::endl;
            return val;
        }
        default: {
            std::cout << "Unhandled token: #" << tree.type() << std::endl;
            return -1;
        }
    }
    return -1;
}
