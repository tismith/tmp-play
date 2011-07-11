#ifndef _FIB_H
#define _FIB_H

template< int i > struct FIB {
    static const int RESULT = FIB< i - 1 >::RESULT + FIB< i - 2 >::RESULT;
};

template< > struct FIB< 1 > {
    static const int RESULT = 1;
};

template< > struct FIB< 2 > {
    static const int RESULT = 1;
};

#endif
