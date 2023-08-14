/*************************************************************************
	> File Name: haizei_parameters.h
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#ifndef _HAIZEI_PARAMETERS_H
#define _HAIZEI_PARAMETERS_H

#include <string>
#include <map>

class Parameters {
public :
    Parameters(std::shared_ptr<Parameters>);
    void define(std::string);
    bool has(std::string);
    int &operator[](std::string);

private:
    std::map<std::string, int> array;
    std::shared_ptr<Parameters> next;
};

#endif
