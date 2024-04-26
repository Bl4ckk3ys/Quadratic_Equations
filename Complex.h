#pragma once
#include "Fraction.h"

class Complex{
private:
    Fraction _im;
    Fraction _re;
public:
    Complex();
    Complex(int num_re, int denom_re, int num_im, int denom_im);
    Complex(Fraction re, Fraction im);

    friend std::ostream& operator<<(std::ostream& os, Complex& tmp){
        if (tmp._re.GetNum() != 0){
            os << tmp._re;
        }
        else{
            if (tmp._im > 0){
            os <<"-"<< tmp._im << "i" ;
            }
            else{
                os <<"+"<< -tmp._im << "i" ;
            }
            return os;
        }
        if (tmp._im.GetNum() == 0){
            return os;
        }
        if (tmp._im > 0){
            os << "+" << tmp._im << "i" ;
        }
        else{
            os << tmp._im << "i" ;
        }
        return os;
    }
    Complex operator+(const Complex& number) const;
    Complex operator=(const Complex& number);
    bool operator==(const Complex& number) const ;
    Complex operator-(){
        return Complex(-_re, -_im);
    }
};