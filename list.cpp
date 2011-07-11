#include <iostream>
#include "list.hpp"

#define myList LIST< 1, LIST< 2, LIST< 3, EmptyList > > >

template <int n> struct SQUARE {
    static const int VALUE = n*n;
};

int main(int argc, char **argv) {
    std::cout << "head = " << myList::HEAD << std::endl;
    std::cout << "sum = " << myList::SUM << std::endl;
    std::cout << "minimum = " << myList::MINIMUM << std::endl;
    std::cout << "map_sum = " << MAP_SUM< myList, SQUARE >::RESULT << std::endl;
}
