#include <iostream>
#include <climits>
#include "list.hpp"

#define myList LIST4<2,3,2,4>::TYPE

template <int n> struct SQUARE {
    static const int VALUE = n*n;
};

template <int n> struct ID {
    static const int VALUE = n;
};

template <int a, int b> struct ADDITION {
    static const int VALUE = a + b;
};

template <int a> struct INCREMENT {
    static const int VALUE = a + 1;
};

template <int a, int b> struct MAX {
    static const int VALUE = a > b ? a : b;
};

template <int a, int b> struct MIN {
    static const int VALUE = a < b ? a : b;
};

int main(int argc, char **argv) {
    std::cout << "The list is: ";
    ListPrinter<myList>::print(); // this one generates tons of classes
    std::cout << "head = " << myList::HEAD << std::endl;
    std::cout << "sum = " << myList::SUM << std::endl;
    std::cout << "minimum = " << myList::MINIMUM << std::endl;
    std::cout << "sum of squares = " << MAP_REDUCE< myList, SQUARE, ADDITION, 0 >::RESULT << std::endl;
    std::cout << "minimum, map_reduce style = " << MAP_REDUCE< myList, ID, MIN, INT_MAX >::RESULT << std::endl;
    std::cout << "sum, map_reduce style = " << MAP_REDUCE< myList, ID, ADDITION, 0 >::RESULT << std::endl;
    std::cout << "map square over the list = ";
    ListPrinter<MAP<myList, SQUARE>::TYPE>::print();
    std::cout << "map increment over the list = ";
    ListPrinter<MAP<myList, INCREMENT >::TYPE>::print();
    std::cout << "prepending '3' = ";
    ListPrinter<PREPEND<3,myList>::TYPE>::print();
    std::cout << "tail myList = ";
    ListPrinter<TAIL<myList>::TYPE>::print();
}
    
