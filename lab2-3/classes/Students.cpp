#include "Students.h"

Students::Students(const Students &c) {
    age = c.age;
    name = c.name;
    surname = c.surname;
    course = c.course;
}

Students::Students(std::string a, std::string b, int c, int d) {
    age = c;
    surname = a;
    name = b;
    course = d;
}

Students::Students(int a) {
    age = 0;
    name = "***";
    surname = "***";
    course = 0;
}

Students &Students::operator=(int a) {
    age = 0;
    name = "***";
    surname = "***";
    course = 0;
    return (*this);
}

Students &Students::operator=(const Students &c) {
    age = c.age;
    name = c.name;
    surname = c.surname;
    course = c.course;
    return (*this);
}

std::istream &operator>>(std::istream &stream, Students &object) {
    std::cout << "Input name, surname, age, course: ";
    stream >> object.surname;
    stream >> object.name;
    stream >> object.age;
    stream >> object.course;
    return stream;
}

std::ostream &operator<<(std::ostream &stream, Students &object) {
    stream << object.surname << " ";
    stream << object.name << " ";
    stream << object.age << " ";
    stream << object.course << "     ";
    return stream;
}

bool Students::operator==(Students &c) const {
    if((age == c.age && course == c.course) && (name == c.name && surname == c.surname)){
        return true;
    }
    return false;
}

