#pragma once
#include "Fraction.h"
#include "Complex.h"

class Square_Equation{   
private:
    Fraction _a;
    Fraction _b;
    Fraction _c;
    Fraction _D;
    Complex _root1;
    Complex _root2;
    void root();
public:
    Square_Equation(Fraction a, Fraction b, Fraction c);
    void print_roots();
    
};