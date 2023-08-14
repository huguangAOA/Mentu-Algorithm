#include <haizei_evaluator.h>
#include <iostream>

int hythonEvaluator::run(ASTree tree, Parameters *p) {
    if (tree.type() == -1) {
        int r = 0;
        for(int i = 0; i < tree.size(); i++) {
            r = run(tree[i], p);
        }
        return r;
    }
    switch(tree.type()) {
        case PRINT: {
            for (int i = 0; i < tree.size(); i++) {
                if (i) std::cout << " ";
                std::cout << run(tree[i], p);
            }
            std::cout << std::endl;
            return 0;
        }
        case BLOCK: {
            Parameters *newp = new Parameters(p);
            for (int i = 0; i < tree.size(); i++) {
                run(tree[i], newp);
            }
            delete newp;
            return 0;
        }
        case AND: return run(tree[0], p) && run(tree[1], p);
        case OR: return run(tree[0], p) || run(tree[1], p);
        case GT: return run(tree[0], p) > run(tree[1], p);
        case LITTLE: return run(tree[0], p) < run(tree[1], p);
        case EQ: return run(tree[0], p) == run(tree[1], p);
        case GE: return run(tree[0], p) >= run(tree[1], p);
        case LE: return run(tree[0], p) <= run(tree[1], p);
        case NE: return run(tree[0], p) != run(tree[1], p);
        case IF: {
            if (run(tree[0], p)) {
                run(tree[1], p);
            } else if (tree.size() == 3) {
                run(tree[2], p);
            }
            return 0;
        }
        case FOR: {
            Parameters *newp = new Parameters(p);
            for (run(tree[0], newp); run(tree[1], newp); run(tree[2], newp)) {
                run(tree[3], newp);
            }
            delete newp;
            return 0;
        }
        case DEF: {
            for (int i = 0; i < tree.size(); i++) {
                std::string name = tree[i].str();
                p->define(name);
                if (tree[i].size()) p->set(name, run(tree[i][0], p));
            }
            return 0;
        }
        case INT: {
            std::string s = tree.str();
            if (s[0] == '-') {
                return -atoi(s.c_str() + 1);
            } else {
                return atoi(s.c_str());
            }
        }
        case ID: {
            return p->get(tree.str());
        }
        case PLUS : return run(tree[0], p) + run(tree[1], p);
        case MINUS: return run(tree[0], p) - run(tree[1], p);
        case TIMES: return run(tree[0], p) * run(tree[1], p);
        case MOD:   return run(tree[0], p) % run(tree[1], p);
        case ASSIGN: {
            std::string var = tree[0].str();
            int val = run(tree[1], p);
            p->set(var, val);
            return val;
        }
        default: {
            std::cout << "Unhandled token: #" << tree.type() << std::endl;
            return -1;
        }
    }
    return -1;
}
