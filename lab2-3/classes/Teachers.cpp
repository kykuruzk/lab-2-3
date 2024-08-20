#include "Teachers.h"

Teachers::Teachers(const Teachers &c) {
    age = c.age;
    name = c.name;
    surname = c.surname;
    subject = c.subject;
}

Teachers::Teachers(std::string a, std::string b, int c, std::string d) {
    age = c;
    surname = a;
    name = b;
    subject = d;
}

Teachers::Teachers(int a) {
    age = 0;
    name = "***";
    surname = "***";
    subject = "***";
}

std::istream &operator>>(std::istream &stream, Teachers &object) {
    std::cout << "Input name, surname, age, subject: ";
    stream >> object.surname;
    stream >> object.name;
    stream >> object.age;
    stream >> object.subject;
    return stream;
}

std::ostream &operator<<(std::ostream &stream, Teachers &object) {
    stream << object.surname << " ";
    stream << object.name << " ";
    stream << object.age << " ";
    stream << object.subject << "     ";
    return stream;
}

bool Teachers::operator==(Teachers &c) const {
    if((age == c.age && subject == c.subject) && (name == c.name && surname == c.surname)){
        return true;
    }
    return false;
}

Teachers &Teachers::operator=(const Teachers &c) {
    age = c.age;
    name = c.name;
    surname = c.surname;
    subject = c.subject;
    return (*this);
}

Teachers &Teachers::operator=(int a) {
    age = 0;
    name = "***";
    surname = "***";
    subject = "***";
    return (*this);
}

