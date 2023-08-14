#include <haizei_parameters.h>

Parameters::Parameters(std::shared_ptr<Parameters> next) : next(next) {}

void Parameters::define(std::string name) {
    if (has(name)) {
        throw std::runtime_error(std::string("redefine variable : ") + name);
    }
    array[name] = 0;
    return ;
}

bool Parameters::has(std::string name) {
    if (array.find(name) == array.end()) {
        return false;
    }
    return true;
}
    
int &Parameters::operator[](std::string name) {
    if (!has(name)) {
        if (next) return next->operator[](name);
        else throw std::runtime_error(std::string("undefine variable : ") + name);
    }
    return array[name];
}
