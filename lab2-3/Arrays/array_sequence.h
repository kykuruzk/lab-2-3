#ifndef LAB2_3_ARRAY_SEQUENCE_H
#define LAB2_3_ARRAY_SEQUENCE_H

#include "../sequence/sequence.h"
#include "../dynamic_array/dynamic_array.h"

template<class T>
class ArraySequence : public Sequence<T> {  // Унаследование от Sequence<T>

private:
    DynamicArray<T> dynamic_array;
public:
    ArraySequence(int _size, T *_data);
    explicit ArraySequence(const DynamicArray<T>& _dynamic_array);
    explicit ArraySequence(int _size);
    ArraySequence(const ArraySequence<T>& _array_sequence);
    ArraySequence() = default;

    T *GetData();
    T GetFirst() const;
    T GetLast() const;
    T GetElement(int index) const;
    int GetSize() const;

    void Append(T element);
    void Prepend(T element);
    void Replace(T element, int index);
    void Insert(T element, int index);
    void Swap(int index_1, int index_2);
    void Resize();

    int IsContained(T element);
    void Concat(ArraySequence<T> &copy);
    ArraySequence<T> GetSub(int a, int b);
};

// Подключение файла с реализацией
#include "array_sequence_impl.h"

#endif // LAB2_3_ARRAY_SEQUENCE_H
