#include <iostream>
#include "Fraction.h"
// #include "Complex.h"
// #include "Square.h"


int main(){
    Fraction a(1);
    Fraction b(1);
    Fraction c = a + b;
    Fraction* prc2 = &c; 
    // Fraction* c = a + b;
    // Fraction** prc2 = &c; 
    // Square_Equation eq(a, b, c);
    // eq.print_roots();


    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<c<< std::endl;
    std::cout<<prc2<<std::endl;
    

    return 0;
}