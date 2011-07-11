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

#endif
