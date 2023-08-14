#include <haizei_parameters.h>
#include <iostream>

Parameters::Parameters(Parameters *next) : next(next) {}

// 在当前作用于定义变量
void Parameters::define(std::string name) {
    if (memory.find(name) != memory.end())  {
        std::cerr << "redefine : " << name << std::endl;
        exit(-1);
    }
    memory[name] = 0;
    return ;
}

// 在当前及其父作用域上修改变量值
void Parameters::set(std::string name, int val) {
    if (memory.find(name) != memory.end()) {
        memory[name] = val;
        return ;
    }
    if (next == nullptr) {
        std::cerr << "unknown identify : " << name << std::endl;
        exit(-1);
    }
    this->next->set(name, val);
    return ;
}

// 在当前及其父作用域上取得变量值
int Parameters::get(std::string name) {
    if (memory.find(name) != memory.end()) {
        return memory[name];
    }
    if (next == nullptr) {
        std::cerr << "unknown identify : " << name << std::endl;
        exit(-1);
    }
    return this->next->get(name);
}
