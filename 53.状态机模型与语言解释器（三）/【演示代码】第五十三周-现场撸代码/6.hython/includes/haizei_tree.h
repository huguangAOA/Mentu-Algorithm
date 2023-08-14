/*************************************************************************
	> File Name: haizei_tree.h
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#ifndef _HAIZEI_TREE_H
#define _HAIZEI_TREE_H

#include <string>
#include <other_headers.h>

class ASTree {
public :
    ASTree(pANTLR3_BASE_TREE); // 构造函数
    std::string str(); // 获取节点的文本信息
    ASTree operator[](int); // 获取某个子树
    int size(); // 获取子树数量
    int type(); // 获取节点类型(INT, PLUS, ....)

private:
    pANTLR3_BASE_TREE tree;
};

#endif
