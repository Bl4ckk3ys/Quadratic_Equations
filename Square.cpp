#include <cmath>
#include "Square.h"


Square_Equation::Square_Equation(Fraction a, Fraction b, Fraction c){
    _a = a;
    _b = b;
    _c = c;
    _D = (_b * _b) - (_a * _c *4);
    root();
}

void Square_Equation::root(){
    if (_D.GetNum() == 0){
        Complex root(Fraction(-_b, _a * 2), Fraction(0));
        _root1 = root;
        _root2 = root;
    }
    else if(_D.GetNum() > 0){
        Fraction z = static_cast<Fraction>(sqrt(_D));
        Fraction first = (-_b - z) /  (_a * 2);  
        _root1 = Complex(first, Fraction(0)); 
        Fraction second = (-_b + z) /  (_a * 2);
        _root2 = Complex(second, Fraction(0));
    }
    else{
        Fraction z = (-_D).sqrt();
        Fraction re = -_b / (_a * 2);
        Fraction im = z / (_a * 2);
        _root1 = Complex(re, im);
        _root2 = Complex (re, -im);
    }
}

void Square_Equation::print_roots(){
    if (_root1 == _root2){
        std::cout<<"x1 = "<< _root1<<std::endl;
        return;
    }
    std::cout<<"x1 = "<<_root1<<std::endl;
    std::cout<<"x2 = "<<_root2<<std::endl;
}

