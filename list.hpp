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

template< class L, template <int> class F , template <int, int> class R, int BASE> 
struct MAP_REDUCE {
    static const int RESULT = BASE;
};

#define LIST4(a, b, c, d) LIST < a, LIST< b, LIST< c, LIST< d, EmptyList > > > >

//include all the template parameters that are used here
template< int a, class TAIL, template <int> class F, template <int, int> class R , int BASE> 
//but only specialse based on what the original template defintion was
struct MAP_REDUCE< LIST< a, TAIL>, F , R, BASE> {
    static const int RESULT = R< F< a >::VALUE, MAP_REDUCE< TAIL, F, R, BASE >::RESULT >::VALUE;
};

#endif
