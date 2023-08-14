/*************************************************************************
	> File Name: haizei_tree.h
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#ifndef _HAIZEI_TREE_H
#define _HAIZEI_TREE_H

#include "hythonLexer.h"
#include "hythonParser.h"
#include <string>

typedef pANTLR3_COMMON_TOKEN ASTreeToken; 

class ASTree {
public :
    explicit ASTree(pANTLR3_BASE_TREE);
    size_t size();
    ASTree operator[](size_t);
    ASTreeToken getToken();
    std::string getText();

private:
    pANTLR3_BASE_TREE tree;
};

#endif
