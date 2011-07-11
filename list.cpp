#include <iostream>
#include "list.hpp"

#define myList LIST< 1, LIST< 2, LIST< 3, EmptyList > > >

template <int n> struct SQUARE {
    static const int VALUE = n*n;
};

template <int a, int b> struct ADDITION {
    static const int VALUE = a + b;
};

int main(int argc, char **argv) {
    std::cout << "head = " << myList::HEAD << std::endl;
    std::cout << "sum = " << myList::SUM << std::endl;
    std::cout << "minimum = " << myList::MINIMUM << std::endl;
    std::cout << "map_reduce = " << MAP_REDUCE< myList, SQUARE, ADDITION >::RESULT << std::endl;
}
