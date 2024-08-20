#include "Chars.h"

Chars::Chars(std::string a) {
    data = a;
}

Chars::Chars(const Chars &c) {
    data = c.data;
}

Chars::Chars(const int a) {
    data = "0";
}

bool Chars::operator==(Chars &c) const {
    if(data == c.data){
        return true;
    }
    return false;
}

Chars &Chars::operator=(const Chars &c) {
    data = c.data;
    return (*this);
}

Chars &Chars::operator=(int a) {
    data = "***";
    return *this;
}

std::istream &operator>>(std::istream &stream, Chars &object) {
    std::cout << "Input char os string: ";
    stream >> object.data;
    return stream;
}

std::ostream &operator<<(std::ostream &stream, Chars &object) {
    stream << object.data;
    return stream;
}
