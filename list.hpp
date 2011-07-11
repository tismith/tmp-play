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

template< class TAIL, template <int> class F , template <int, int> class R > 
struct MAP_REDUCE {
    static const int RESULT = 0;
};

template< int a, class TAIL, template <int> class F, template <int, int> class R > 
struct MAP_REDUCE< LIST< a, TAIL>, F , R> {
    static const int RESULT = R< F< a >::VALUE, MAP_REDUCE< TAIL, F, R >::RESULT >::VALUE;
};

template< template <int> class F , template <int, int> class R> 
struct MAP_REDUCE< EmptyList, F, R > {
    static const int RESULT = 0;
};

#endif
