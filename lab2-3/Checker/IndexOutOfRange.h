#ifndef LAB2_3_INDEXOUTOFRANGE_H
#define LAB2_3_INDEXOUTOFRANGE_H

#include <exception>
#define WrongIndex 1

class IndexOutOfRange: std::exception {
private:
    int errorCode;
    const char* msg;
public:
    static const char* IndexErrorList (int msg);
    explicit IndexOutOfRange(int msgCode);
};


#endif
