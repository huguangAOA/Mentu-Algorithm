/*************************************************************************
	> File Name: utility.h
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#ifndef _UTILITY_H
#define _UTILITY_H

#include "demoLexer.h"
#include "demoParser.h"
#include <haizei_tree.h>

ASTree fromFileBuildASTree(int argc, char *argv[]);
void destroyASTree();
pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE, unsigned);
const char* getText(pANTLR3_BASE_TREE tree);

#endif
