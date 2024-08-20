#ifndef ARRAY_SEQUENCE_TESTS_H
#define ARRAY_SEQUENCE_TESTS_H
#include "../Arrays/array_sequence.h"
#include <cassert>




void test_AS_constructor(){
    int arr_1[5];
    for(int i = 0; i < 5; i++){
        arr_1[i] = i+2;
    }
    ArraySequence<int> test_class_1 = ArraySequence<int>(5, arr_1);
    for (int i = 0; i < 5; i++)
        assert(test_class_1.GetElement(i) == i+2);
    assert(test_class_1.GetSize() == 5);
    double arr_2[5];
    for (int i = 0; i < 5; i++)
        arr_2[i] = (i/7);
    ArraySequence<double> test_class_2 = ArraySequence<double>(5, arr_2);
    assert(test_class_2.GetSize() == 5);
    ArraySequence<int> test_class_3 = ArraySequence<int>(5);
    ArraySequence<int> test_class_4 = ArraySequence<int>(test_class_3);
    assert(test_class_3.GetSize() == test_class_4.GetSize());
}



void test_AS_get_element(){
    int arr_1[5];
    for(int i = 0; i < 5; i++){
        arr_1[i] = i+2;
    }
    ArraySequence<int> test_class_1 = ArraySequence<int>(5, arr_1);
    for (int i = 0; i < 5; i++)
        assert(test_class_1.GetElement(i) == i+2);
    double arr_2[5];
    for(int i = 0; i < 5; i++){
        arr_2[i] = i/7;
    }
    ArraySequence<double> test_class_2 = ArraySequence<double>(5, arr_2);
    for (int i = 0; i < 5; i++)
        assert(test_class_2.GetElement(i) == i/7);
}

void test_AS_append(){
    int arr_1[5];
    for(int i = 0; i < 5; i++){
        arr_1[i] = i;
    }
    ArraySequence<int> test_class_2 = ArraySequence<int>(5, arr_1);
    test_class_2.Append(3);
    assert(test_class_2.GetElement(test_class_2.GetSize() - 1) == 3);
}

void test_AS_prepend(){
    int arr_1[5];
    for(int i = 0; i < 5; i++){
        arr_1[i] = i;
    }
    ArraySequence<int> test_class_2 = ArraySequence<int>(5, arr_1);
    test_class_2.Prepend(3);
    assert(test_class_2.GetElement(0) == 3);
}

void test_AS_insert(){
    int arr_1[5];
    for(int i = 0; i < 5; i++){
        arr_1[i] = i;
    }
    ArraySequence<int> test_class_2 = ArraySequence<int>(5, arr_1);
    test_class_2.Insert(0,1);
    assert(test_class_2.GetElement(1) == 0);
}
void test_AS_replace(){
    int arr_1[4] = {1,3,4,5};
    ArraySequence<int> test_class_1 = ArraySequence<int>(4, arr_1);
    test_class_1.Replace(11,0);
    assert(test_class_1.GetElement(0) == 11);
}
void test_AS_swap(){
    int arr_1[4] = {1,3,4,5};
    ArraySequence<int> test_class_1 = ArraySequence<int>(4, arr_1);
    test_class_1.Swap(0,3);
    assert(test_class_1.GetElement(0) == 5);
    assert(test_class_1.GetElement(3) == 1);
}
void test_AS_concat(){
    int tt[4] = {1,2,3,4};
    int ttt[4] = {5,6,7,8};
    ArraySequence<int> test1 = ArraySequence<int>(4, tt);
    ArraySequence<int> test2 = ArraySequence<int>(4, ttt);
    test1.Concat(test2);
    ArraySequence<int> test = test1.GetSub(0,4);
    assert(test.GetSize() == 5);
}
void test_AS_getsub(){
    int tt[4] = {1,2,3,4};
    int ttt[4] = {5,6,7,8};
    ArraySequence<int> test1 = ArraySequence<int>(4, tt);
    ArraySequence<int> test2 = ArraySequence<int>(4, ttt);
    test1.Concat(test2);
    ArraySequence<int> test = test1.GetSub(0,4);
    assert(test1.GetSize() == 8);
}

void start_AS_tests(){
    test_AS_constructor();
    test_AS_append();
    test_AS_get_element();
    test_AS_prepend();
    test_AS_insert();
    test_AS_replace();
    test_AS_swap();
    test_AS_getsub();
    test_AS_concat();
}

#endif // ARRAY_SEQUENCE_TESTS_H
