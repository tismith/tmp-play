#ifndef _LIST_H
#define _LIST_H
#include <iostream>
#include "conditional.hpp"

// basic lists and their constructors
struct EmptyList {};

template< int a, typename L > struct LIST {
    static const int HEAD = a;
    //experimented with putting operations in the nodes
    typedef L TAIL;
    static const int MINIMUM = a < L::MINIMUM ? a : L::MINIMUM;
    static const int LENGTH = 1 + L::LENGTH;
};

template< int a > struct LIST< a, EmptyList > {
    static const int HEAD = a;
    typedef EmptyList TAIL;
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

template< class L> 
struct SUM {
	static const int RESULT = 0;
};  

//include all the template parameters that are used here for 
//a template specialisation
template< int a, class TAIL>
struct SUM< LIST< a, TAIL> > {    
	static const int RESULT =  a + SUM<TAIL>::RESULT;
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

// tuple data structure
template <typename A, typename B> struct PAIR {
    typedef A FST;
    typedef B SND;
};

//split - splits a list into two halves -- needs a PAIR
template < class L > struct SPLIT {};

template <> struct SPLIT <EmptyList> {
    typedef PAIR<EmptyList, EmptyList> TYPE;
};

template <int a> struct SPLIT <LIST<a,EmptyList> > {
    typedef PAIR<LIST<a,EmptyList>, EmptyList> TYPE;
};

template <int a, int b, typename TAIL> 
struct SPLIT<LIST<a, LIST<b, TAIL> > > {
    private:
    typedef typename SPLIT<TAIL>::TYPE _SPLIT_REC;
    public:
    typedef PAIR<
        typename PREPEND<a, typename _SPLIT_REC::FST>::TYPE, 
        typename PREPEND<b, typename _SPLIT_REC::SND>::TYPE
        > TYPE;
};

//merge - take two sorted lists and return a sorted merged list -- needs an IF
template < template <int, int> class P, class L1, class L2> struct MERGE {};

template < template <int, int> class P, class L2> 
struct MERGE< P, EmptyList, L2> {
    typedef L2 TYPE;
};

template < template <int, int> class P, class L1> 
struct MERGE< P, L1, EmptyList > {
    typedef L1 TYPE;
};

template < template <int, int> class P, int A1, class TAIL1, int A2, class TAIL2> 
struct MERGE< P, LIST<A1, TAIL1>, LIST<A2, TAIL2> > {
    typedef typename IF< P < A1, A2 >::VALUE, 
            PREPEND< A1, typename MERGE <P, TAIL1, LIST<A2, TAIL2> >::TYPE >, 
            PREPEND< A2, typename MERGE <P, LIST<A1, TAIL1>, TAIL2>::TYPE > >
            ::TEST::TYPE TYPE;
};

//merge sort -- uses split and merge
//Uses the algorithm from <http://en.literateprograms.org/Merge_sort_(Haskell)>
template < template <int, int> class P, class L >
struct SORT {
    private:
    typedef typename SPLIT<L>::TYPE _SPLIT_LIST;
    typedef typename SORT<P, typename _SPLIT_LIST::FST>::TYPE _L1;
    typedef typename SORT<P, typename _SPLIT_LIST::SND>::TYPE _L2;
    public:
    typedef typename MERGE<P,_L1,_L2>::TYPE TYPE;
};

template < template <int, int> class P > struct SORT<P, EmptyList> {
    typedef EmptyList TYPE;
};

template < template <int, int> class P, int a> 
struct SORT<P, LIST<a, EmptyList> > {
    typedef LIST<a, EmptyList> TYPE;
};

#endif
