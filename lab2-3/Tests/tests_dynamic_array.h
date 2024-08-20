#ifndef DYNAMIC_ARRAY_TESTS_H
#define DYNAMIC_ARRAY_TESTS_H
#include "../dynamic_array/dynamic_array.h"
#include <cassert>




void test_DA_constructor(){
    int arr_1[5];
    for(int i = 0; i < 5; i++){
        arr_1[i] = i+2;
    }
    DynamicArray<int> test_class_1 = DynamicArray<int>(5, arr_1);
    for (int i = 0; i < 5; i++)
        assert(test_class_1.GetElement(i) == i+2);
    assert(test_class_1.GetSize() == 5);
    double arr_2[5];
    for (int i = 0; i < 5; i++)
        arr_2[i] = (i/7);
    DynamicArray<double> test_class_2 = DynamicArray<double>(5, arr_2);
    assert(test_class_2.GetSize() == 5);
    DynamicArray<int> test_class_3 = DynamicArray<int>(5);
    DynamicArray<int> test_class_4 = DynamicArray<int>(test_class_3);
    assert(test_class_3.GetSize() == test_class_4.GetSize());
}


void test_DA_get_element(){
    int arr_1[5];
    for(int i = 0; i < 5; i++){
        arr_1[i] = i+2;
    }
    DynamicArray<int> test_class_1 = DynamicArray<int>(5, arr_1);
    for (int i = 0; i < 5; i++)
        assert(test_class_1.GetElement(i) == i+2);
    double arr_2[5];
    for(int i = 0; i < 5; i++){
        arr_2[i] = i/7;
    }
    DynamicArray<double> test_class_2 = DynamicArray<double>(5, arr_2);
    for (int i = 0; i < 5; i++)
        assert(test_class_2.GetElement(i) == i/7);
}

void test_DA_append(){
    int arr_1[5];
    for(int i = 0; i < 5; i++){
        arr_1[i] = i;
    }
    DynamicArray<int> test_class_2 = DynamicArray<int>(5, arr_1);
    test_class_2.Append(3);
    assert(test_class_2.GetElement(test_class_2.GetSize() - 1) == 3);
}

void test_DA_prepend(){
    int arr_1[5];
    for(int i = 0; i < 5; i++){
        arr_1[i] = i;
    }
    DynamicArray<int> test_class_2 = DynamicArray<int>(5, arr_1);
    test_class_2.Prepend(3);
    assert(test_class_2.GetElement(0) == 3);
}

void test_DA_insert(){
    int arr_1[5];
    for(int i = 0; i < 5; i++){
        arr_1[i] = i;
    }
    DynamicArray<int> test_class_2 = DynamicArray<int>(5, arr_1);
    test_class_2.Insert(111,4);
    assert(test_class_2.GetElement(4) == 111);
}
void test_DA_replace(){
    int arr_1[4] = {1,3,4,5};
    DynamicArray<int> test_class_1 = DynamicArray<int>(4, arr_1);
    test_class_1.Replace(11,0);
    assert(test_class_1.GetElement(0) == 11);
}
void test_DA_swap(){
    int arr_1[4] = {1,3,4,5};
    DynamicArray<int> test_class_1 = DynamicArray<int>(4, arr_1);
    test_class_1.Swap(0,3);
    assert(test_class_1.GetElement(0) == 5);
    assert(test_class_1.GetElement(3) == 1);
}
void test_DA_concat(){
    int tt[4] = {1,2,3,4};
    int ttt[4] = {5,6,7,8};
    DynamicArray<int> test1 = DynamicArray<int>(4, tt);
    DynamicArray<int> test2 = DynamicArray<int>(4, ttt);
    test1.Concat(test2);
    DynamicArray<int> test = test1.GetSub(0,4);
    assert(test.GetSize() == 5);
}
void test_DA_getsub(){
    int tt[4] = {1,2,3,4};
    int ttt[4] = {5,6,7,8};
    DynamicArray<int> test1 = DynamicArray<int>(4, tt);
    DynamicArray<int> test2 = DynamicArray<int>(4, ttt);
    test1.Concat(test2);
    DynamicArray<int> test = test1.GetSub(0,4);
    assert(test1.GetSize() == 8);
}
void start_DA_tests(){
    test_DA_constructor();
    test_DA_append();
    test_DA_get_element();
    test_DA_prepend();
    test_DA_insert();
    test_DA_swap();
    test_DA_replace();
    test_DA_getsub();
    test_DA_concat();
}

#endif
