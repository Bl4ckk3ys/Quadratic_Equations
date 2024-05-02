#include "Fraction.h"
#include <cmath>

void Fraction::SetNum(int32_t num){
    _num = num;
}

void Fraction::SetDenom(uint32_t denom){
    if(denom == 0) throw "Denom cannot be 0.";
    _denom = denom;
}

Fraction::Fraction(int32_t num, uint32_t denom){
    SetNum(num);
    SetDenom(denom);
}

void Fraction::Print(){
    if(_denom == 1) std::cout << _num << std::endl;
    else std::cout << _num << "/" << _denom << std::endl;
}
int Fraction::NOD(uint32_t num1, uint32_t num2){
    if(num1%num2==0) 
        return num2;
    if(num2%num1==0) 
        return num1;
    if(num1>num2)
        return NOD(num1%num2,num2);
    return NOD(num1,num2%num1);
}
void Fraction::Reduction(){
    int nod = NOD(fabs(_num), _denom);
    _num = _num / nod;
    _denom = _denom / nod;
}

int Fraction::Len(double copy){
    int temp, count= 0, lenght = 1;
    while(1){
        temp = (int)(copy * 10) % 10;
        copy *= 10;
        if (temp == 0){
            count++;
            if (count == 5) break;
            continue;
        }
        else{
            lenght += count;
            count = 0;
        }
        lenght++;
        if (lenght == 12) break;
    }
    return lenght;
}

Fraction::Fraction(double number){
    if (number == 0){
        _num = 0;
        _denom = 1;
        return;
    }
    int32_t number1 = fabs(number), number2 = 0, lenght;
    double copy = number;
    lenght = 6;
    for (int i = 0; i < lenght; i++){
        number *= 10;
        number2 = number2 * 10 + (int)(number) % 10;
    }
    int32_t num = fabs(number);
    if (number != 0)  
        num = number1 * pow(10, lenght) + fabs(number2);
    uint32_t denum = pow(10, lenght);
    int nod = 1;
    if (num > denum) nod = NOD(num, denum);
    else nod = NOD(denum, num);
    if (number > 0) _num = num / nod;
    else _num = (-1 * (int32_t)num) / nod;
    _denom = denum / nod;
}
 
Fraction::Fraction(const Fraction& fraction){
    _num = fraction._num;
    _denom = fraction._denom;
    std::cout<<"Копирую"<<std::endl;
}

Fraction::Fraction(){
    _num = 0;
    _denom = 1;
}