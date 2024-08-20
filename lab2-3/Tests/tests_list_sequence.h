#ifndef LIST_SEQUENCE_TESTS_H
#define LIST_SEQUENCE_TESTS_H

#include <cassert>
#include "../list_sequence/list_sequence.h"


void test_LS_constructor(){
    int arr_1[5] = {1,2,3,4,5};
    ListSequence<int> test_class_1 = ListSequence<int>(5, arr_1);
    for(int i = 0; i < 5; i++){
        assert(test_class_1.GetElement(i) == i+1);
    }
    assert(test_class_1.GetSize() == 5);
}

void test_LS_append(){
    int arr_1[5] = {1,2,3,4,5};
    ListSequence<int> test_class_1 = ListSequence<int>(5, arr_1);
    test_class_1.Append(6);
    assert(test_class_1.GetElement(test_class_1.GetSize() - 1) == 6);
    double arr_2[5] = {1/4,2/4,3/2,4/6,5/6};
    ListSequence<double> test_class_2 = ListSequence<double>(5, arr_2);
    test_class_1.Append(6/18);
    assert(test_class_1.GetElement(test_class_1.GetSize() - 1) == 1/3);
}

void test_LS_get_element(){
    int arr_1[5] = {1,2,3,4,5};
    ListSequence<int> test_class_1 = ListSequence<int>(5, arr_1);
    for(int i = 0; i < 5; i++){
        assert(test_class_1.GetElement(i) == i+1);
    }
}
void test_LS_insert(){
    int arr_1[4] = {1,3,4,5};
    ListSequence<int> test_class_1 = ListSequence<int>(4, arr_1);
    test_class_1.Insert(2,1);
    assert(test_class_1.GetElement(1) == 2);
}

void test_LS_prepend(){
    int arr_1[4] = {1,3,4,5};
    ListSequence<int> test_class_1 = ListSequence<int>(4, arr_1);
    test_class_1.Prepend(0);
    assert(test_class_1.GetElement(0) == 0);
}
void test_LS_resize(){
    int arr_1[4] = {1,3,4,5};
    ListSequence<int> test_class_1 = ListSequence<int>(4, arr_1);
    test_class_1.Resize(6);
    assert(test_class_1.GetSize() == 6);
}
void test_LS_swap(){
    int arr_1[4] = {1,3,4,5};
    ListSequence<int> test_class_1 = ListSequence<int>(4, arr_1);
    test_class_1.Swap(0,1);
    assert(test_class_1.GetElement(0) == 3);
    assert(test_class_1.GetElement(1) == 1);
}
void test_LS_replace(){
    int arr_1[4] = {1,3,4,5};
    ListSequence<int> test_class_1 = ListSequence<int>(4, arr_1);
    test_class_1.Replace(11,0);
    assert(test_class_1.GetElement(0) == 11);
}

void test_LS_concat(){
    int tt[4] = {1,2,3,4};
    int ttt[4] = {5,6,7,8};
    ListSequence<int> test1 = ListSequence<int>(4, tt);
    ListSequence<int> test2 = ListSequence<int>(4, ttt);
    test1.Concat(test2);
    ListSequence<int> test = test1.GetSub(0,4);
    assert(test.GetSize() == 5);
}
void test_LS_getsub(){
    int tt[4] = {1,2,3,4};
    int ttt[4] = {5,6,7,8};
    ListSequence<int> test1 = ListSequence<int>(4, tt);
    ListSequence<int> test2 = ListSequence<int>(4, ttt);
    test1.Concat(test2);
    ListSequence<int> test = test1.GetSub(0,4);
    assert(test1.GetSize() == 8);
}

void start_LS_tests(){
    test_LS_constructor();
    test_LS_append();
    test_LS_get_element();
    test_LS_insert();
    test_LS_prepend();
    test_LS_resize();
    test_LS_swap();
    test_LS_replace();
    test_LS_concat();
    test_LS_getsub();
}

#endif