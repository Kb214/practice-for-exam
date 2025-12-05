#include <iostream>

/*allows you to make functions and classes
    uses compile-time polymorphism:  decided at compile time, 0 runtime costs, produces faster code*/
template <typename T>

T max(T a, T b){
    /*return if a is greater than b. a if true, b if false*/
    return (a > b) ? a : b;
}

/*need to define your template after each different function you make
 template DO NOT carry over to other functions */
template <typename T>  

T add(T a, T b){
    return a + b; 
}
/* Templates are NOT types, they are patterns*/

int main(){
    std::cout << max(4,9) << "\n";
    std::cout << max(5,3) << "\n";

    std::cout << add(4.4,9.6) << "\n";
    std::cout << add(5,3) << "\n";


    return 0;
}
