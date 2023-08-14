/*************************************************************************
	> File Name: haizei_evaluator2.h
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#ifndef _HAIZEI_EVALUATOR_H
#define _HAIZEI_EVALUATOR_H

#include <utility.h>
#include <haizei_tree.h>
#include <haizei_parameters.h>

class ExprTreeEvaluator {
public:
    int run(ASTree, std::shared_ptr<Parameters>);
};

#endif
