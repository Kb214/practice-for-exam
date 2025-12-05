#include <iostream>


int sum (int a, int b){
    return a + b;
}

int sum (int a, double b){
    return a + b;
}

double sum (double a, double b){
    return a + b;
}

double sum(double a, int b){
    return a + b;
}

int main(){

    std::cout << sum(2, 9) << "\n";
    std::cout << sum(3.5, 8.4) << "\n";
    std::cout << sum(2.7, 6) << "\n";

    return 0;
}