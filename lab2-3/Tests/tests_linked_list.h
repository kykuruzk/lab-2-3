#ifndef LINKED_LIST_TESTS_H
#define LINKED_LIST_TESTS_H
#include <cassert>
#include "../linked_list/linked_list.h"

void test_LL_constructor(){
    int arr_1[5] = {1,2,3,4,5};
    LinkedList<int> test_class_1 = LinkedList<int>(5, arr_1);
    for(int i = 0; i < 5; i++){
        assert(test_class_1.GetElement(i) == i+1);
    }
    assert(test_class_1.GetSize() == 5);
}

void test_LL_append(){
    int arr_1[5] = {1,2,3,4,5};
    LinkedList<int> test_class_1 = LinkedList<int>(5, arr_1);
    test_class_1.Append(6);
    assert(test_class_1.GetElement(test_class_1.GetSize() - 1) == 6);
    double arr_2[5] = {1/4,2/4,3/2,4/6,5/6};
    LinkedList<double> test_class_2 = LinkedList<double>(5, arr_2);
    test_class_1.Append(6/18);
    assert(test_class_1.GetElement(test_class_1.GetSize() - 1) == 1/3);
}

void test_LL_get_element(){
    int arr_1[5] = {1,2,3,4,5};
    LinkedList<int> test_class_1 = LinkedList<int>(5, arr_1);
    for(int i = 0; i < 5; i++){
        assert(test_class_1.GetElement(i) == i+1);
    }
}
void test_LL_insert(){
    int arr_1[4] = {1,3,4,5};
    LinkedList<int> test_class_1 = LinkedList<int>(4, arr_1);
    test_class_1.Insert(2,1);
    assert(test_class_1.GetElement(1) == 2);
}

void test_LL_prepend(){
    int arr_1[4] = {1,3,4,5};
    LinkedList<int> test_class_1 = LinkedList<int>(4, arr_1);
    test_class_1.Prepend(0);
    assert(test_class_1.GetElement(0) == 0);
}

void test_LL_resize(){
    int arr_1[4] = {1,3,4,5};
    LinkedList<int> test_class_1 = LinkedList<int>(4, arr_1);
    test_class_1.Resize(6);
    assert(test_class_1.GetSize() == 6);
}
void test_LL_swap(){
    int arr_1[4] = {1,3,4,5};
    LinkedList<int> test_class_1 = LinkedList<int>(4, arr_1);
    test_class_1.Swap(0,1);
    assert(test_class_1.GetElement(0) == 3);
    assert(test_class_1.GetElement(1) == 1);
}
void test_LL_replace(){
    int arr_1[4] = {1,3,4,5};
    LinkedList<int> test_class_1 = LinkedList<int>(4, arr_1);
    test_class_1.Replace(11,0);
    assert(test_class_1.GetElement(0) == 11);
}
void test_LL_concat(){
    int tt[4] = {1,2,3,4};
    int ttt[4] = {5,6,7,8};
    LinkedList<int> test1 = LinkedList<int>(4, tt);
    LinkedList<int> test2 = LinkedList<int>(4, ttt);
    test1.Concat(test2);
    LinkedList<int> test = test1.GetSub(0,4);
    assert(test.GetSize() == 5);
}
void test_LL_getsub(){
    int tt[4] = {1,2,3,4};
    int ttt[4] = {5,6,7,8};
    LinkedList<int> test1 = LinkedList<int>(4, tt);
    LinkedList<int> test2 = LinkedList<int>(4, ttt);
    test1.Concat(test2);
    LinkedList<int> test = test1.GetSub(0,4);
    assert(test1.GetSize() == 8);
}

void start_LL_tests(){
    test_LL_constructor();
    test_LL_append();
    test_LL_get_element();
    test_LL_insert();
    test_LL_prepend();
    test_LL_resize();
    test_LL_swap();
    test_LL_replace();
    test_LL_getsub();
    test_LL_concat();
}

#endif