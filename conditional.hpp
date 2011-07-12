#ifndef _CONDITIONAL_H
#define _CONDITIONAL_H

// dodgy if
template< bool CONDITION, class THEN, class ELSE > struct IF {};

template<class THEN, class ELSE> struct IF< false, THEN, ELSE > {
    typedef ELSE TEST;
};

template<class THEN, class ELSE> struct IF< true, THEN, ELSE > {
    typedef THEN TEST;
};

#endif
