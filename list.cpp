#include <iostream>
#include <climits>
#include "list.hpp"

typedef LIST5<10,23,4,2,9>::TYPE myList;

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

template <int a, int b> struct ORD {
    static const bool VALUE = a < b;
};

int main(int argc, char **argv) {

    /* The best example */
    std::cout << "The list is: ";
    ListPrinter<myList>::print(); // this one generates tons of classes

    std::cout << "The sorted list is: ";
    ListPrinter<SORT<ORD, myList>::TYPE>::print();

    /* basic list operations */
    std::cout << "head = " << myList::HEAD << std::endl;
    std::cout << "length = " << myList::LENGTH << std::endl;
    std::cout << "sum = " << SUM< myList >::RESULT << std::endl;
    std::cout << "minimum = " << myList::MINIMUM << std::endl;

    /* map-reduce or fold */
    std::cout << "sum of squares with map_reduce = " << MAP_REDUCE< myList, SQUARE, ADDITION, 0 >::RESULT << std::endl;
    std::cout << "minimum with map_reduce = " << MAP_REDUCE< myList, ID, MIN, INT_MAX >::RESULT << std::endl;
    std::cout << "sum done with map_reduce = " << MAP_REDUCE< myList, ID, ADDITION, 0 >::RESULT << std::endl;
    std::cout << "mapping square over the list = ";
    ListPrinter<MAP<myList, SQUARE>::TYPE>::print();
    std::cout << "mapping increment over the list = ";
    ListPrinter<MAP<myList, INCREMENT >::TYPE>::print();

    /* other list operations */
    std::cout << "prepending '3' = ";
    ListPrinter<PREPEND<3,myList>::TYPE>::print();
    std::cout << "tail function = ";
    ListPrinter<TAIL<myList>::TYPE>::print();
    std::cout << "tail member function = ";
    ListPrinter<myList::TAIL>::print();

    /* internal routines used for the merge sort */
    std::cout << "merge (1,6,8) (6,9) = ";
    ListPrinter<MERGE<ORD, LIST3<1,6,8>::TYPE, LIST2<6,9>::TYPE>::TYPE>::print();
    std::cout << "fst . split (1,6,8,6,9) = ";
    ListPrinter<SPLIT<LIST5<1,6,8,6,9>::TYPE>::TYPE::FST>::print();
    std::cout << "snd . split (1,6,8,6,9) = ";
    ListPrinter<SPLIT<LIST5<1,6,8,6,9>::TYPE>::TYPE::SND>::print();
}
    
