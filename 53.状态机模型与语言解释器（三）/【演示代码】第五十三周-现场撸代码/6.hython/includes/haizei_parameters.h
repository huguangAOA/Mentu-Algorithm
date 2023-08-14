/*************************************************************************
	> File Name: haizei_parameters.h
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#ifndef _HAIZEI_PARAMETERS_H
#define _HAIZEI_PARAMETERS_H
#include <map>
#include <string>

class Parameters {
public :
    Parameters(Parameters *next = nullptr);
    void define(std::string);   // 在当前作用于定义变量
    void set(std::string, int); // 在当前及其父作用域上修改变量值
    int get(std::string);       // 在当前及其父作用域上取得变量值

private:
    Parameters *next;
    std::map<std::string, int> memory;
};

#endif
