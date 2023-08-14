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
    demoEvaluator eval;
    ASTree tree = fromFileBuildASTree(argc, argv);
    int rr = eval.run(tree); // 执行代码
    cout << "Evaluator result: " << rr << '\n';
    destroyASTree();
    return 0;
}
