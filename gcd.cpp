#include <iostream>
#include "gcd.hpp"

int main(int argc, char **argv) {
    std::cout << "GCD (25,50) == " << GCD<25, 50>::RESULT << std::endl;
}