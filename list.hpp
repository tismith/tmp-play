#ifndef _LIST_H
#define _LIST_H
#include <iostream>

// basic lists and their constructors
struct EmptyList {};

template< int a, typename L > struct LIST {
    static const int HEAD = a;
    //experimented with putting operations in the nodes
    typedef L TAIL;
    static const int SUM = a + L::SUM;
    static const int MINIMUM = a < L::MINIMUM ? a : L::MINIMUM;
    static const int LENGTH = 1 + L::LENGTH;
};

template< int a > struct LIST< a, EmptyList > {
    static const int HEAD = a;
    typedef EmptyList TAIL;
    static const int SUM = a;
    static const int MINIMUM = a;
    static const int LENGTH = 1;
};

template<int a> struct LIST1 {
    typedef LIST<a, EmptyList > TYPE;
};
template<int a, int b> struct LIST2 {
    typedef LIST<a, LIST<b, EmptyList > > TYPE;
};
template<int a, int b, int c> struct LIST3 {
    typedef LIST<a, LIST<b, LIST<c, EmptyList > > > TYPE;
};
template<int a, int b, int c, int d> struct LIST4 {
    typedef LIST<a, LIST<b, LIST<c, LIST<d, EmptyList > > > > TYPE;
};
template<int a, int b, int c, int d, int e> struct LIST5 {
    typedef LIST<a, LIST<b, LIST<c, LIST<d, LIST<e, EmptyList > > > > > TYPE;
};

// printing lists to std::cout
template <class L> struct ListPrinter {
    static inline void print(void) {
        std::cout << std::endl;
    }
};

template <int a> struct ListPrinter<LIST<a, EmptyList> > {
    static inline void print(void) {
        std::cout << a;
        ListPrinter<EmptyList>::print();
    }
};

template <int a, class TAIL> struct ListPrinter<LIST<a,TAIL> > {
    static inline void print(void) {
        std::cout << a << ", "; 
        ListPrinter<TAIL>::print();
    }
};

// prepend
template< int a, class L>
struct PREPEND {
    typedef LIST<a,EmptyList> TYPE;
};

template< int a, int b, class TAIL>
struct PREPEND<a,LIST<b,TAIL> > {
    typedef LIST<a, LIST< b, TAIL> > TYPE;
};

// tail
template<class L> 
struct TAIL {
    typedef EmptyList TYPE;
};

template<int a, class T> 
struct TAIL<LIST<a,T> > {
    typedef T TYPE;
};

// map over lists
template< class L, template <int> class F> 
struct MAP {
    typedef EmptyList TYPE;
};

template< int a, class TAIL, template <int> class F>
struct MAP<LIST<a,TAIL>, F> {
    //I need the typename, otherwise it thinks the MAP::TYPE is a value
    typedef LIST< F< a >::VALUE, typename MAP<TAIL, F>::TYPE > TYPE;
};

// map reduce over lists
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
