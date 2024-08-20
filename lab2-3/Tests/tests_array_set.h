#ifndef ARRAY_SET_TESTS_H
#define ARRAY_SET_TESTS_H

#include <cassert>
#include "../Arrays/array_set.h"

void tests_array_set() {
    ArraySet<int> test1;
    ArraySet<int> test2;
    ArraySet<int> test3;
    ArraySet<int> test4;
    ArraySet<int> test5;
    test1.Add(2);
    test1.Add(3);
    test1.Add(5);
    test2.Add(5);
    test2.Add(2);
    test2.Add(3);

    assert(test1.Equals(test2));
    assert((test1.Union(test2)).Equals(test2));
    test2.Add(10);
    assert(test2.Contains(10));
    test1.Add(10);
    test4 = test1.Difference(test2);
    assert(test4.Equals(test5));
};

#endif // ARRAY_SET_TESTS_H
