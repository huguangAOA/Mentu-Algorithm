/*************************************************************************
	> File Name: haizei_evaluator.h
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#ifndef _HAIZEI_EVALUATOR_H
#define _HAIZEI_EVALUATOR_H
#include <haizei_tree.h>
#include <string>
#include <map>

class demoEvaluator {
    std::map<std::string,int> memory;
public:
    int run(ASTree);
};

#endif
