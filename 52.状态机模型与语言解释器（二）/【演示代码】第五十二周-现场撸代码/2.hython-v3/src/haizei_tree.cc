#include <haizei_tree.h>

ASTree::ASTree(pANTLR3_BASE_TREE tree) : tree(tree) {} 

size_t ASTree::size() {
    return tree->getChildCount(tree);
}

ASTree ASTree::operator[](size_t ind) {
    assert(ind < tree->getChildCount(tree));
    return ASTree((pANTLR3_BASE_TREE)tree->getChild(tree, ind));
}

ASTreeToken ASTree::getToken() {
    return tree->getToken(tree);
}

std::string ASTree::getText() {
    return (const char *)tree->getText(tree)->chars;
}
