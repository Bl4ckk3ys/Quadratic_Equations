#pragma once
#include "Fraction.h"
#include "Complex.h"

class square{   
private:
    Fraction _a;
    Fraction _b;
    Fraction _c;
    Fraction _D;
    Complex _root1;
    Complex _root2;
public:
    square(Fraction a, Fraction b, Fraction c);
    void root();
    void print();
    void print_root();
};