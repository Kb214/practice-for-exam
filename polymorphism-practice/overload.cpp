#include "overloading-operators.h"
#include "overloading-operators.cpp"
#include <iostream>

int main(){
    //input the values a is lfs and b is rhs
    Add a(10);
    Add b(20);

    Add c = a + b;

    std::cout << "a + b = " << c << "\n";


    return 0;
}