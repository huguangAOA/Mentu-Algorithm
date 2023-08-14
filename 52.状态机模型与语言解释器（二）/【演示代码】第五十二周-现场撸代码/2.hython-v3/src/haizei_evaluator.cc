#include <haizei_evaluator.h>
#include <iostream>

int ExprTreeEvaluator::run(ASTree tree, std::shared_ptr<Parameters> p) {
    ASTreeToken tok= tree.getToken();
    switch(tok->type) {
        case BLOCK: {
            p = std::make_shared<Parameters>(p);
            for(int i = 0; i < tree.size(); i++) {
                run(tree[i], p);
            }
            return 0;
        } break;
        case DEF: {
            for (int i = 0; i < tree.size(); i += 1) {
                p->define(tree[i].getText());
                if (tree[i].size()) {
                    (*p)[tree[i].getText()] = run(tree[i][0], p);
                }
            }
        } break;
        case FOR : {
            p = std::make_shared<Parameters>(p);
            for (run(tree[0], p); run(tree[1], p); run(tree[2], p)) {
                run(tree[3], p);
            }
        } break;
        case IF : {
            if (run(tree[0], p)) run(tree[1], p);
            else if (tree.size() == 3) run(tree[2], p);
        } break;
        case LITTLE: return run(tree[0], p) < run(tree[1], p);
        case LE: return run(tree[0], p) <= run(tree[1], p);
        case GT: return run(tree[0], p) > run(tree[1], p);
        case GE: return run(tree[0], p) >= run(tree[1], p);
        case EQ: return run(tree[0], p) == run(tree[1], p);
        case NE: return run(tree[0], p) != run(tree[1], p);
        case PRINT: {
            for (int i = 0; i < tree.size(); i++) {
                i && printf(" ");
                printf("%d", run(tree[i], p));
            }
            printf("\n");
        } break;
        case INT: {
            std::string s = tree.getText();
            if(s[0] == '~') return -atoi(s.c_str()+1);
            return atoi(s.c_str());
        }
        case ID: return (*p)[tree.getText()];
        case PLUS: return run(tree[0], p) + run(tree[1], p);
        case MINUS: return run(tree[0], p) - run(tree[1], p);
        case TIMES: return run(tree[0], p) * run(tree[1], p);
        case DIV: return run(tree[0], p) / run(tree[1], p);
        case ASSIGN: {
            int val = (*p)[tree[0].getText()] = run(tree[1], p);
            return val;
        }
        default: {
            std::cout << "Unhandled token: #" << tok->type << std::endl;
            return -1;
        }
    }
    return 0;
}
