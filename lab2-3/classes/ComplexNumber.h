#ifndef LAB2_3_COMPLEXNUMBER_H
#define LAB2_3_COMPLEXNUMBER_H
#include <istream>

class ComplexNumber {
private:
    double Re = 0;
    double Im = 0;

public:
    ComplexNumber()= default;
    explicit ComplexNumber(int a);
    ComplexNumber(double re, double im);
    ComplexNumber(const ComplexNumber &c);
    ComplexNumber& operator = (const ComplexNumber& c);
    bool operator == (ComplexNumber& c) const;
    ComplexNumber& operator = (int a);
    friend std::istream& operator >> (std::istream& stream, ComplexNumber& object);
    friend std::ostream& operator<<(std::ostream & stream, ComplexNumber & object);
};


#endif
