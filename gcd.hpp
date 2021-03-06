#ifndef _GCD_H
#define _GCD_H

template< int a, int b > struct GCD {
    static const int RESULT = GCD< b, a % b >::RESULT;
};

template< int a > struct GCD< a, 0 > {
    static const int RESULT = a;
};

#endif
