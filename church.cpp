#include <iostream>
#include "church.hpp"

int main(int argc, char **argv) {
    std::cout << "AND(TRUE,TRUE) == ";
    std::cout << (typeid(AND::F<TRUE,TRUE>::TYPE) == typeid(TRUE)); 
    std::cout << std::endl;

    std::cout << "AND(FALSE,TRUE) == ";
    std::cout << (typeid(AND::F<FALSE,TRUE>::TYPE) == typeid(TRUE)); 
    std::cout << std::endl;
};
