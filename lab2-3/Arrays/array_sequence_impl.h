#ifndef LAB2_3_ARRAY_SEQUENCE_IMPL_H
#define LAB2_3_ARRAY_SEQUENCE_IMPL_H
#include "array_sequence.h"

template<class T>
ArraySequence<T>::ArraySequence(int _size, T *_data) {
    dynamic_array = DynamicArray<T>(_size, _data);
}

template<class T>
ArraySequence<T>::ArraySequence(const DynamicArray<T>& _dynamic_array) {
    dynamic_array = DynamicArray<T>(_dynamic_array);
}

template<class T>
ArraySequence<T>::ArraySequence(int _size) {
    dynamic_array = DynamicArray<T>(_size);
}

template<class T>
ArraySequence<T>::ArraySequence(const ArraySequence<T>& _array_sequence) {
    dynamic_array = _array_sequence.dynamic_array;
}

template<class T>
T* ArraySequence<T>::GetData() {
    return dynamic_array.GetData();
}

template<class T>
T ArraySequence<T>::GetFirst() const {
    return dynamic_array.GetElement(0);
}

template<class T>
T ArraySequence<T>::GetLast() const {
    return dynamic_array.GetElement(dynamic_array.GetSize() - 1);
}

template<class T>
T ArraySequence<T>::GetElement(int index) const {
    return dynamic_array.GetElement(index);
}

template<class T>
int ArraySequence<T>::GetSize() const {
    return dynamic_array.GetSize();
}

template<class T>
void ArraySequence<T>::Append(T element) {
    dynamic_array.Append(element);
}

template<class T>
void ArraySequence<T>::Prepend(T element) {
    dynamic_array.Prepend(element);
}

template<class T>
void ArraySequence<T>::Replace(T element, int index) {
    dynamic_array.Replace(element, index);
}

template<class T>
void ArraySequence<T>::Insert(T element, int index) {
    dynamic_array.Insert(element, index);
}

template<class T>
void ArraySequence<T>::Swap(int index_1, int index_2) {
    dynamic_array.Swap(index_1, index_2);
}

template<class T>
void ArraySequence<T>::Resize() {
    dynamic_array.Resize();
}

template<class T>
int ArraySequence<T>::IsContained(T element) {
    for (int i = 0; i < dynamic_array.GetSize(); i++) {
        if (dynamic_array.GetElement(i) == element) {
            return 1;
        }
    }
    return 0;
}

template<class T>
void ArraySequence<T>::Concat(ArraySequence<T>& copy) {
    dynamic_array.Concat(copy.dynamic_array);
}

template<class T>
ArraySequence<T> ArraySequence<T>::GetSub(int start, int end) {
    // Получаем подпоследовательность из DynamicArray
    DynamicArray<T> subArray = dynamic_array.GetSub(start, end);

    // Создаем новый объект ArraySequence и возвращаем его
    ArraySequence<T> subSequence(subArray); // Используем конструктор с DynamicArray

    return subSequence;
}


#endif
