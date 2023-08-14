/*************************************************************************
	> File Name: main.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <utility.h>
#include <haizei_tree.h>
#include <haizei_evaluator.h>
#include <iostream>
using std::cout;

int main(int argc, char* argv[]) {
    hythonEvaluator eval;
    ASTree tree = fromFileBuildASTree(argc, argv);
    Parameters *p = new Parameters();
    eval.run(tree, p); // 执行代码
    destroyASTree();
    return 0;
}
