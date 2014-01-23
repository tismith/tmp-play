#include <iostream>
#include "conditional.hpp"

struct A {
    static const int RESULT = 1;
};

struct B {
    static const int RESULT = 0;
};

struct A1 {
    static inline void EXEC(void) {
        std::cout << "TRUE!";
    }
};

struct B1 {
    static inline void EXEC(void) {
        std::cout << "FALSE!";
    }
};

int main(int argc, char **argv) {
    std::cout << "true = " << IF<true, A, B>::TEST::RESULT << std::endl;
    std::cout << "false = " << IF<false, A, B>::TEST::RESULT << std::endl;

    std::cout << "true = ";
    IF<true, A1, B1>::TEST::EXEC();
    std::cout << std::endl;
}
