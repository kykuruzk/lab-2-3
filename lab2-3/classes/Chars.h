#ifndef LAB2_3_CHARS_H
#define LAB2_3_CHARS_H

#include <iostream>

class Chars {
private:
    std::string data;

public:
    Chars()= default;
    explicit Chars(std::string a);
    Chars(const Chars &c);
    explicit Chars(const int a);
    bool operator == (Chars& c) const;
    Chars& operator = (const Chars& c);
    Chars& operator = (int a);
    friend std::istream& operator >> (std::istream& stream, Chars& object);
    friend std::ostream& operator << (std::ostream& stream, Chars& object);
};


#endif
