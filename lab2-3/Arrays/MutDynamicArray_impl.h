#ifndef LAB2_3_MUTDYNAMICARRAY_IMPL_H
#define LAB2_3_MUTDYNAMICARRAY_IMPL_H

#include "mutdynamicarray.h"

template<typename T>
MutDynamicArray<T>::MutDynamicArray() : DynamicArray<T>() {}

template<typename T>
MutDynamicArray<T>::MutDynamicArray(const DynamicArray<T>& array) : DynamicArray<T>(array) {}

template<typename T>
MutDynamicArray<T>::MutDynamicArray(int _size) : DynamicArray<T>(_size) {}

template<typename T>
MutDynamicArray<T>::MutDynamicArray(int _size, T* _data) : DynamicArray<T>(_size, _data) {}

template<typename T>
MutDynamicArray<T>::~MutDynamicArray() {}

template<typename T>
MutDynamicArray<T>& MutDynamicArray<T>::Replace(T element, int index) {
    if (index < 0 || index >= this->GetSize()) {
        throw std::out_of_range("Index out of range");
    }
    this->data[index] = element;
    return *this;
}

template<typename T>
MutDynamicArray<T>& MutDynamicArray<T>::Resize() {
    if (this->capacity == 0) {
        this->capacity = 2;
    } else {
        this->capacity *= 2;
    }
    T* old_data = this->data;
    this->data = new T[this->capacity];
    for (int i = 0; i < this->size; i++) {
        this->data[i] = old_data[i];
    }
    delete[] old_data;
    return *this;
}

template<typename T>
MutDynamicArray<T>& MutDynamicArray<T>::Append(T element) {
    this->Insert(element, this->size);
    return *this;
}

template<typename T>
MutDynamicArray<T>& MutDynamicArray<T>::Prepend(T element) {
    this->Insert(element, 0);
    return *this;
}

template<typename T>
MutDynamicArray<T>& MutDynamicArray<T>::Swap(int index_1, int index_2) {
    if (index_1 >= this->GetSize() || index_1 < 0 || index_2 >= this->GetSize() || index_2 < 0) {
        throw std::out_of_range("Index out of range");
    }
    T temp = this->data[index_1];
    this->data[index_1] = this->data[index_2];
    this->data[index_2] = temp;
    return *this;
}

template<typename T>
MutDynamicArray<T>& MutDynamicArray<T>::Insert(T element, int index) {
    if (index > this->GetSize() || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    if (this->GetFree() == 0) {
        this->Resize();
    }
    this->size += 1;
    for (int i = this->size - 1; i > index; i--) {
        this->data[i] = this->data[i - 1];
    }
    this->data[index] = element;
    return *this;
}

template<typename T>
MutDynamicArray<T>& MutDynamicArray<T>::Concat(DynamicArray<T>& copy) {
    int new_size = copy.GetSize() + this->size;
    int new_capacity = 2 * new_size;
    T* new_data = new T[new_capacity];
    for (int i = 0; i < this->size; i++) {
        new_data[i] = this->GetElement(i);
    }
    for (int i = 0; i < copy.GetSize(); i++) {
        new_data[this->size + i] = copy.GetElement(i);
    }
    this->size = new_size;
    this->capacity = new_capacity;
    delete[] this->data;
    this->data = new_data;
    return *this;
}

#endif // LAB2_3_MUTDYNAMICARRAY_IMPL_H
