#include <iostream>
#include <typeinfo>
#include "church.hpp"

int main() {
    std::cout << "AND(TRUE,TRUE) == ";
    std::cout << (typeid(AND::F<TRUE,TRUE>::TYPE) == typeid(TRUE)); 
    std::cout << std::endl;

    std::cout << "AND(FALSE,TRUE) == ";
    std::cout << (typeid(AND::F<FALSE,TRUE>::TYPE) == typeid(TRUE)); 
    std::cout << std::endl;

    std::cout << "OR(FALSE,TRUE) == ";
    std::cout << (typeid(OR::F<FALSE,TRUE>::TYPE) == typeid(TRUE)); 
    std::cout << std::endl;

#if 0
    std::cout << "NOT(TRUE) == ";
    std::cout << (typeid(NOT::F<TRUE>::TYPE) == typeid(TRUE)); 
    std::cout << std::endl;

    std::cout << "NOT(FALSE) == ";
    std::cout << (typeid(NOT::F<FALSE>::TYPE) == typeid(TRUE)); 
    std::cout << std::endl;
#endif
}
