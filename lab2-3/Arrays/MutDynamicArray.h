#ifndef LAB2_3_MUTDYNAMICARRAY_H
#define LAB2_3_MUTDYNAMICARRAY_H

#include <stdexcept>
#include "../dynamic_array/dynamic_array.h"

template<typename T>
class MutDynamicArray : public DynamicArray<T> {
public:
    MutDynamicArray();
    MutDynamicArray(const DynamicArray<T>& array);
    MutDynamicArray(int _size);
    MutDynamicArray(int _size, T* _data);
    ~MutDynamicArray();

    MutDynamicArray& Replace(T element, int index);
    MutDynamicArray& Resize();
    MutDynamicArray& Append(T element);
    MutDynamicArray& Prepend(T element);
    MutDynamicArray& Swap(int index_1, int index_2);
    MutDynamicArray& Insert(T element, int index);
    MutDynamicArray& Concat(DynamicArray<T>& copy);
};

#include "mutdynamicarray_impl.h"

#endif // LAB2_3_MUTDYNAMICARRAY_H
