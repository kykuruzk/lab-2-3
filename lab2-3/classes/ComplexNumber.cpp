#include "ComplexNumber.h"
#include <iostream>

ComplexNumber::ComplexNumber(int a) {
    Re = 0;
    Im = 0;
}

ComplexNumber::ComplexNumber(double re, double im) {
    Re = re;
    Im = im;
}

ComplexNumber::ComplexNumber(const ComplexNumber &c) {
    Re = c.Re;
    Im = c.Im;
}

ComplexNumber& ComplexNumber::operator = (const ComplexNumber& c)
{
    Re = c.Re;
    Im = c.Im;
    return (*this);
}

bool ComplexNumber::operator==(ComplexNumber &c) const {
    if(Re == c.Re && Im == c.Im){
        return true;
    }
    return false;
}

ComplexNumber &ComplexNumber::operator=(int a) {
    Re = 0;
    Im = 0;
    return (*this);
}

std::istream &operator>>(std::istream &stream, ComplexNumber &object) {
    std::cout << "Input Re and Im: ";
    stream >> object.Re;
    stream >> object.Im;
    return stream;
}

std::ostream &operator<<(std::ostream &stream, ComplexNumber &object) {
    stream << object.Re;
    if(object.Im >= 0){
        stream << '+' << object.Im << 'i';
    }
    else{
        stream<< object.Im << 'i';
    }
    return stream;
}


