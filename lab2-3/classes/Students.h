#ifndef LAB2_3_STUDENTS_H
#define LAB2_3_STUDENTS_H

#include <iostream>

class Students {
private:
    int age;
    std::string name;
    std::string surname;
    int course;

public:
    Students()= default;
    Students(const Students &c);
    Students(std::string a, std::string b, int c, int d);
    explicit Students(int a);
    Students& operator = (int a);
    Students& operator = (const Students& c);
    friend std::istream& operator >> (std::istream& stream, Students& object);
    friend std::ostream& operator << (std::ostream& stream, Students& object);
    bool operator == (Students& c) const;
};


#endif
