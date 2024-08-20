#ifndef LAB2_3_DYNAMIC_ARRAY_H
#define LAB2_3_DYNAMIC_ARRAY_H

#include "../Checker/IndexOutOfRange.h"
#include "../Checker/errors.h"

template<typename T>
class DynamicArray {
protected:
    T* data = nullptr;
    int size = 0;
    int capacity = 0;
public:
    DynamicArray();
    DynamicArray(const DynamicArray<T> &array);
    DynamicArray(int _size);
    DynamicArray(int _size, T* _data);
    DynamicArray& operator=(const DynamicArray<T> &array);
    ~DynamicArray();

    int GetSize() const;
    int GetCapacity();
    int GetFree();
    T* GetData();
    T GetElement(int index) const;

    virtual DynamicArray& Replace(T element, int index);
    virtual DynamicArray& Resize();
    virtual DynamicArray& Append(T element);
    virtual DynamicArray& Prepend(T element);
    virtual DynamicArray& Swap(int index_1, int index_2);
    virtual DynamicArray& Insert(T element, int index);
    virtual DynamicArray& Concat(DynamicArray<T> &copy);

    DynamicArray<T> GetSub(int index_1, int index_2);
};

#endif
