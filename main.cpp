#include <iostream>
#include "Fraction.h"
#include "Complex.h"
#include "Square.h"


int main(){
    Fraction a(1);
    Fraction b(1);
    Fraction c(54);
    // Square_Equation eq(a, b, c);
    // eq.print_roots();

    a = a + b;
    b = b + a + 1;

    std::cout<<a<< std::endl;
    std::cout<<b<< std::endl;
    return 0;
}