#include "IndexOutOfRange.h"


const char *IndexOutOfRange::IndexErrorList(int msg) {
    if (msg == WrongIndex){

        auto string = "Wrong Index\n";
        return string;
    }
    auto string = "Error\n";
    return string;
}

IndexOutOfRange::IndexOutOfRange(int msgCode):
        exception(),
        errorCode(msgCode),
        msg(IndexErrorList(msgCode)) {
}
