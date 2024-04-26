#include <iostream>
#include "Fraction.h"
#include "Complex.h"
#include "Square.h"


int main(){
    Fraction a(1, 1);
    Fraction b(0, 1);
    Fraction c(1, 1);
    square first(a, b, c);
    first.print_root();
    return 0;
}