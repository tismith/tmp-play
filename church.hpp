#ifndef _CHURCH_H
#define _CHURCH_H

// church encoded booleans
//TRUE = \a\b -> a
struct TRUE {
    template <typename A, typename B> struct F {
        typedef A TYPE;
    };
};

//FALSE = \a\b -> b
struct FALSE {
    template <typename A, typename B> struct F {
        typedef B TYPE;
    };
};

//AND = \m\n -> m n m
struct AND {
    template <typename M, typename N> struct F {
        typedef typename M:: template F<N,M>::TYPE TYPE;
    };
};

#endif
