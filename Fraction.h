#pragma once
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <cmath>

class Fraction{
private: 
    int32_t _num;
    uint32_t _denom;
    int NOD(uint32_t num, uint32_t denom);
    int Len(double copy);
    
public:
    Fraction();
    Fraction(int32_t num, uint32_t denom);
    Fraction(double num);
    void Reduction();
    void SetNum(int32_t num);
    void SetDenom(uint32_t denom);
    void Print();
    inline int32_t GetNum(){
        return _num;
    }
    inline uint32_t GetDenom(){
        return _denom;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& tmp){
        if (tmp._denom == 1){
            os << tmp._num;
            return os;
        }
        os << tmp._num << "/" << tmp._denom;
        return os;
    }

    Fraction operator+(Fraction& fraction) const {
        int32_t new_num = _num * fraction._denom + fraction._num * _denom;
        uint32_t new_denom = fraction._denom * _denom;
        return Fraction(new_num, new_denom);
    }

    Fraction operator+(double number) const {
        int res = _num  + number * _denom;
        return Fraction(res, _denom);
    }

    Fraction operator-(const Fraction& fraction) const {
        int32_t new_num = _num * fraction._denom - _denom * fraction._num;
        uint32_t new_denom = _denom * fraction._denom;
        return Fraction(new_num, new_denom);
    }

    Fraction operator-(double number) const {
        int res = _num  - number * _denom;
        return Fraction(res, _denom);
    }

    Fraction operator*(const Fraction& fract) const {
        int32_t new_num = _num * fract._num;
        uint32_t new_denom = _denom * fract._denom;
        return Fraction(new_num, new_denom);
    }

    Fraction operator*(int number){
        int32_t num = _num * number;
        return Fraction(num, _denom);
    }

    Fraction operator/(const Fraction& fract) const {
        int32_t new_num = _num * fract._denom;
        uint32_t new_denom = _denom * fract._num;
        return Fraction(new_num, new_denom);
    }

    Fraction& operator=(const Fraction& fract){
        _num = fract._num;
        _denom = fract._denom;
        return *this;
    }

    bool operator>(int number) const {
        return _num > number;
    }

    bool operator<(const Fraction& fract) const {
        return (_num * (int32_t)fract._denom < fract._num * (int32_t)_denom);
    }

    bool operator>(const Fraction& fract) const {
        return (_num * (int32_t)fract._denom > fract._num * (int32_t)_denom);
    }

    bool operator>=(const Fraction& fract) const {
        return (_num * (int32_t)fract._denom >= fract._num * (int32_t)_denom);
    }

    bool operator<=(const Fraction& fract) const {
        return ((_num * static_cast<int32_t>(fract._denom)) <= (fract._num * (int32_t)_denom));
    }

    bool operator==(const Fraction& fract) const {
        return (_num * static_cast<int32_t>(fract._denom) == fract._num * static_cast<int32_t>(_denom));
    }

    bool operator!=(const Fraction& fract) const {
        return (_num * static_cast<int32_t>(fract._denom) != fract._num * static_cast<int32_t>(_denom));
    }

    Fraction operator^(int number) const {
        int32_t num = 1;
        int32_t denom = 1;
        for (int i = 0; i < number; i++){
            num *= _num;
            denom *= _denom;
        }
        return Fraction(num, denom);
    }

    // Fraction operator--(){
    //     return Fraction(_num * -1, _denom);
    // }

    Fraction operator++(){
        _num += _denom;
        return *this;
    }

    Fraction operator--(){
        _num -= _denom;
        return *this;
    }

    Fraction operator++(int number){
        Fraction copy = Fraction(_num, _denom);
        _num += _denom;
        return copy;
    }

    Fraction operator--(int number){
        Fraction copy = Fraction(_num, _denom);
        _num -= _denom;
        return copy;
    }

    Fraction operator-()const{
        Fraction fract(-_num,_denom);
        return fract;
    }
    Fraction sqrt(){
        double tmp = static_cast<double>(_num) / _denom;
        tmp = std::sqrt(tmp);
        return Fraction(tmp);
    }

    operator double() const {
        return static_cast<double>(_num) / _denom;
    }

    
};  
