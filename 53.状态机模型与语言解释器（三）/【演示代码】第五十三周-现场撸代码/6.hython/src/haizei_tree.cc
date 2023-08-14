#include <haizei_tree.h>
#include <utility.h>

// 构造函数
ASTree::ASTree(pANTLR3_BASE_TREE tree) : tree(tree) {}

// 获取节点的文本信息
std::string ASTree::str() {
    return std::string(getText(tree));
}

// 获取某个子树
ASTree ASTree::operator[](int ind) {
    assert(ind >= 0 && ind < size());
    return ASTree(getChild(tree, ind));
}

// 获取子树数量
int ASTree::size() {
    return tree->getChildCount(tree);
}

// 获取节点类型(INT, PLUS, ....)
int ASTree::type() {
    pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
    if (!tok) return -1;
    return tok->type;
}
