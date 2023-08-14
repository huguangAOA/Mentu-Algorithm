/*************************************************************************
	> File Name: utilities.h
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#ifndef _UTILITY_H
#define _UTILITY_H

#include "hythonLexer.h"
#include "hythonParser.h"
#include "haizei_tree.h"

ASTree getASTree(int, char *[]);
pANTLR3_BASE_TREE buildAntlrTree(int, char *[]);
void destoryAntlrTree();

#endif
