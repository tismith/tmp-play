#include <iostream>
#include "list.hpp"

#define myList LIST< 1, LIST< 2, LIST< 3, EmptyList > > >

int main(int argc, char **argv) {
    std::cout << "head = " << myList::HEAD << std::endl;
    std::cout << "sum = " << myList::SUM << std::endl;
    std::cout << "minimum = " << myList::MINIMUM << std::endl;
}
