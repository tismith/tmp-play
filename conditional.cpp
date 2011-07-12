#include <iostream>
#include "conditional.hpp"

struct A {
    static const int RESULT = 1;
};

struct B {
    static const int RESULT = 0;
};

int main(int argc, char **argv) {
    std::cout << "true = " << IF<true, A, B>::TEST::RESULT << std::endl;
    std::cout << "true = " << IF<false, A, B>::TEST::RESULT << std::endl;
}
