#include "dynamic_array.h"

template<typename T>
DynamicArray<T>::DynamicArray() = default;

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &array) {
    size = array.size;
    capacity = array.capacity;
    data = new T[capacity];
    for (int i = 0; i < capacity; i++) {
        data[i] = array.data[i];
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(int _size) {
    if (_size < 0) {
        throw IndexOutOfRange(WrongIndex);
    }
    size = _size;
    capacity = 2 * size;
    data = new T[capacity];
    for (int i = 0; i < capacity; i++) {
        data[i] = 0;
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(int _size, T* _data) {
    if (_size < 0) {
        throw IndexOutOfRange(WrongIndex);
    }
    size = _size;
    capacity = 2 * size;
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = _data[i];
    }
    for (int i = size; i < capacity; i++) {
        data[i] = 0;
    }
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T> &array) {
    if (this == &array) {
        return *this;
    }
    size = array.size;
    capacity = array.capacity;
    delete[] data;
    data = new T[capacity];
    for (int i = 0; i < capacity; i++) {
        data[i] = array.data[i];
    }
    return *this;
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template<typename T>
int DynamicArray<T>::GetSize() const {
    return size;
}

template<typename T>
int DynamicArray<T>::GetCapacity() {
    return capacity;
}

template<typename T>
int DynamicArray<T>::GetFree() {
    return capacity - size;
}

template<typename T>
T* DynamicArray<T>::GetData() {
    T* temp = new T[GetSize()];
    for (int i = 0; i < GetSize(); i++) {
        temp[i] = data[i];
    }
    return temp;
}

template<typename T>
T DynamicArray<T>::GetElement(int index) const {
    if (index < 0 || index >= GetSize()) {
        throw IndexOutOfRange(WrongIndex);
    }
    return data[index];
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::Replace(T element, int index) {
    if (index < 0 || index >= GetSize()) {
        throw IndexOutOfRange(WrongIndex);
    }
    data[index] = element;
    return *this;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::Resize() {
    if (capacity == 0) {
        capacity = 2;
    } else {
        capacity = 2 * capacity;
    }
    T* old_data = data;
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = old_data[i];
    }
    for (int i = size; i < capacity; i++) {
        data[i] = 0;
    }
    delete[] old_data;
    return *this;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::Append(T element) {
    Insert(element, size);
    return *this;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::Prepend(T element) {
    Insert(element, 0);
    return *this;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::Swap(int index_1, int index_2) {
    if ((index_1 >= GetSize() || index_1 < 0) || (index_2 >= GetSize() || index_2 < 0)) {
        throw IndexOutOfRange(WrongIndex);
    }
    T temp = data[index_1];
    data[index_1] = data[index_2];
    data[index_2] = temp;
    return *this;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::Insert(T element, int index) {
    if (index > GetSize() || index < 0) {
        throw IndexOutOfRange(WrongIndex);
    }
    if (GetFree() == 0) {
        Resize();
    }
    size += 1;
    for (int i = size - 1; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = element;
    return *this;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::Concat(DynamicArray<T> &copy) {
    int new_size = copy.size + size;
    int new_capacity = 2 * new_size;
    int size_of_concat = copy.GetSize();
    T* new_data = new T[new_capacity];
    for (int i = 0; i < size; i++) {
        new_data[i] = GetElement(i);
    }
    for (int i = 0; i < size_of_concat; i++) {
        new_data[size + i] = copy.GetElement(i);
    }
    size = new_size;
    capacity = new_capacity;
    delete[] data;
    data = new_data;
    return *this;
}

template<typename T>
DynamicArray<T> DynamicArray<T>::GetSub(int index_1, int index_2) {
    if (index_2 < index_1) {
        throw IndexOutOfRange(WrongIndex);
    }
    if ((index_1 >= GetSize() || index_1 < 0) || (index_2 >= GetSize() || index_2 < 0)) {
        throw IndexOutOfRange(WrongIndex);
    }
    T* temp = new T[index_2 - index_1 + 1];
    for (int i = index_1; i <= index_2; i++) {
        temp[i - index_1] = data[i];
    }
    DynamicArray<T> class_return = DynamicArray<T>(index_2 - index_1 + 1, temp);
    delete[] temp;
    return class_return;
}


template class DynamicArray<int>;
template class DynamicArray<double>;
template class DynamicArray<float>;

