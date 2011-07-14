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

//OR = \m\n -> m m n
struct OR {
    template <typename M, typename N> struct F {
        typedef typename M:: template F<M,N>::TYPE TYPE;
    };
};

#if 0
//NOT = \m\a\b -> m b a 
//Doesn't work, my boolean's are matching the empty definition...
struct NOT {
    template <typename C> struct F {};
};
template <typename A, typename B, typename M> 
struct NOT::F <typename M:: template F<A, B> >{
    typedef typename M:: template F<B,A>::TYPE TYPE;
};
#endif
#endif
