#ifndef _CONDITIONAL_H
#define _CONDITIONAL_H

// dodgy if
template< bool CONDITION, class THEN, class ELSE > struct IF  {
    static const int RESULT = THEN::RESULT;
};

template<class THEN, class ELSE> struct IF< false, THEN, ELSE > {
    static const int RESULT = ELSE::RESULT;
};

#endif
