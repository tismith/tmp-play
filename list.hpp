#ifndef _LIST_H
#define _LIST_H
#include <iostream>

struct EmptyList {};

template< int a, typename L > struct LIST {
    static const int HEAD = a;
    static const int SUM = a + L::SUM;
    static const int MINIMUM = a < L::MINIMUM ? a : L::MINIMUM;
};

template< int a > struct LIST< a, EmptyList > {
    static const int HEAD = a;
    static const int SUM = a;
    static const int MINIMUM = a;
};

template<int a, int b, int c, int d> struct LIST4 {
    typedef LIST<a, LIST<b, LIST<c, LIST<d, EmptyList > > > > TYPE;
};

// alternate style list definition
#define LIST5(a, b, c, d, e) LIST < a, LIST< b, LIST< c, LIST< d, LIST< e, EmptyList > > > > >

template <class L> struct ListPrinter {
    static void print(void) {
        std::cout << std::endl;
    }
};

template <int a> struct ListPrinter<LIST<a, EmptyList> > {
    static void print(void) {
        std::cout << a;
        ListPrinter<EmptyList>::print();
    }
};

template <int a, class TAIL> struct ListPrinter<LIST<a,TAIL> > {
    static void print(void) {
        std::cout << a << ", "; 
        ListPrinter<TAIL>::print();
    }
};

template< class L, template <int> class F , template <int, int> class R, int BASE> 
struct MAP_REDUCE {
    static const int RESULT = BASE;
};

//include all the template parameters that are used here
template< int a, class TAIL, template <int> class F, template <int, int> class R , int BASE> 
//but only specialse based on what the original template defintion was
struct MAP_REDUCE< LIST< a, TAIL>, F , R, BASE> {
    static const int RESULT = R< F< a >::VALUE, MAP_REDUCE< TAIL, F, R, BASE >::RESULT >::VALUE;
};

#endif
