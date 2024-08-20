cmake_minimum_required(VERSION 3.26)
project(lab2_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2_3 main.cpp
        classes/ComplexNumber.cpp
        classes/ComplexNumber.h
        classes/Students.cpp
        classes/Students.h
        classes/Teachers.cpp
        classes/Teachers.h
        classes/Chars.cpp
        classes/Chars.h
        linked_list/linked_list.h
        Checker/IndexOutOfRange.cpp
        Checker/IndexOutOfRange.h
        Checker/errors.h
        dynamic_array/dynamic_array.h
        sequence/sequence.h
        Arrays/array_sequence.h
        Arrays/array_set.h
        dynamic_array/dynamic_array.cpp
        list_sequence/list_sequence.h
        Tests/tests_array_sequence.h
        Tests/tests_array_set.h
        Tests/tests_dynamic_array.h
        Tests/tests_linked_list.h
        Tests/tests_list_sequence.h
        Arrays/MutDynamicArray.h
        Arrays/array_sequence_impl.h
        Arrays/array_set_impl.h
        list_sequence/list_sequence_impl.h
        linked_list/linked_list_impl.h
        Arrays/MutDynamicArray_impl.h)
