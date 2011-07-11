#ifndef _LIST_H
#define _LIST_H

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

template< class TAIL, template <int> class F > 
struct MAP_SUM {
    static const int RESULT = 0;
};

template< int a, class TAIL, template <int> class F > 
struct MAP_SUM< LIST< a, TAIL>, F > {
    static const int RESULT = F< a >::VALUE + MAP_SUM< TAIL, F >::RESULT;
};

template< template <int> class F > 
struct MAP_SUM< EmptyList, F > {
    static const int RESULT = 0;
};

#endif
