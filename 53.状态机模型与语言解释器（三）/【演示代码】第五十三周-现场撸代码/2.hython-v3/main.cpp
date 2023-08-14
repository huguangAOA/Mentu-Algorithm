#include <iostream>
#include <utility.h>
#include <haizei_tree.h>
#include <haizei_evaluator.h>

int main(int argc, char* argv[]) {
    ASTree tree = getASTree(argc, argv);
    
    ExprTreeEvaluator eval;
    std::shared_ptr<Parameters> p = std::make_shared<Parameters>(nullptr);
    eval.run(tree, p);

    destoryAntlrTree();
    return 0;
}

