/*************************************************************************
	> File Name: main.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include "demoLexer.h"
#include "demoParser.h"
#include <cassert>
#include <map>
#include <string>
#include <iostream>
using std::map;
using std::string;
using std::cout;

class demoEvaluator {
    map<string,int> memory;
public:
    int run(pANTLR3_BASE_TREE);
};

pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE, unsigned);
const char* getText(pANTLR3_BASE_TREE tree);

int main(int argc, char* argv[]) {
    pANTLR3_INPUT_STREAM input;
    pdemoLexer lex;
    pANTLR3_COMMON_TOKEN_STREAM tokens;
    pdemoParser parser;
    assert(argc > 1);
    
    input = antlr3FileStreamNew((pANTLR3_UINT8)argv[1],ANTLR3_ENC_8BIT);
    lex = demoLexerNew(input);
    tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
    parser = demoParserNew(tokens);
    demoParser_prog_return r = parser->prog(parser);
    pANTLR3_BASE_TREE tree = r.tree;
    
    demoEvaluator eval;
    int rr = eval.run(tree);
    cout << "Evaluator result: " << rr << '\n';
    
    parser->free(parser);
    tokens->free(tokens);
    lex->free(lex);
    input->close(input);
    return 0;
}

int demoEvaluator::run(pANTLR3_BASE_TREE tree) {
    pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
    if (tok) {
        switch(tok->type) {
            case INT: {
                const char* s = getText(tree);
                if (s[0] == '~') {
                    return -atoi(s+1);
                } else {
                    return atoi(s);
                }
            }
            case ID: {
                string var(getText(tree));
                return memory[var];
            }
            case PLUS: return run(getChild(tree,0)) + run(getChild(tree,1));
            case MINUS: return run(getChild(tree,0)) - run(getChild(tree,1));
            case TIMES: return run(getChild(tree,0)) * run(getChild(tree,1));
            case ASSIGN: {
                string var(getText(getChild(tree,0)));
                int val = run(getChild(tree,1));
                memory[var] = val;
                return val;
            }
            default: {
                cout << "Unhandled token: #" << tok->type << '\n';
                return -1;
            }
        }
    } else {
        int k = tree->getChildCount(tree);
        int r = 0;
        for(int i = 0; i < k; i++) {
            r = run(getChild(tree, i));
        }
        return r;
    }
}

pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE tree, unsigned i) {
    assert(i < tree->getChildCount(tree));
    return (pANTLR3_BASE_TREE) tree->getChild(tree, i);
}

const char* getText(pANTLR3_BASE_TREE tree) {
    return (const char*) tree->getText(tree)->chars;
}
