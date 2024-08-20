#ifndef LAB2_3_TEACHERS_H
#define LAB2_3_TEACHERS_H

#include <iostream>

class Teachers {
private:
    int age;
    std::string name;
    std::string surname;
    std::string subject;
public:
    Teachers()= default;
    Teachers(const Teachers &c);
    Teachers(std::string a, std::string b, int c, std::string d);
    explicit Teachers(int a);
    bool operator == (Teachers& c) const;
    Teachers& operator = (const Teachers& c);
    Teachers& operator = (int a);
    friend std::istream& operator >> (std::istream& stream, Teachers& object);
    friend std::ostream& operator << (std::ostream& stream, Teachers& object);
};


#endif
