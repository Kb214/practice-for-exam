#include <iostream>
#include "overloading-operators.h"



Add::Add(int v) : val(v) {}


Add operator+(const Add& lhs, const Add& rhs){
    //return what we add
    return Add(lhs.val + rhs.val);
}


std::ostream& operator<<(std::ostream& os, const Add& a) {
    //os on the left and value on the right
    os << a.val;
    //return out stream
    return os;
}
