#ifndef LAB2_3_LINKED_LIST_H
#define LAB2_3_LINKED_LIST_H

#include <algorithm>
#include "../Checker/IndexOutOfRange.h"

using namespace std;

template<class T>
class LinkedList {
private:
    struct List {
        T data;
        List* next;
    };

    List* head = nullptr;
    List* tail = nullptr;
    int size = 0;

public:
    LinkedList();
    LinkedList(int _size, T* _data);
    LinkedList& operator=(const LinkedList<T>& array);
    LinkedList(int _size);
    LinkedList(const LinkedList<T>& linked_list);
    ~LinkedList();

    void Prepend(T element);
    void Append(T element);
    void Insert(T element, int index);

    T GetFirst() const;
    T GetLast() const;
    int GetSize() const;
    T GetElement(int index) const;

    void Resize(int _size);
    void Replace(T element, int index);
    void Swap(int index_1, int index_2);
    void Concat(LinkedList<T>& copy);
    LinkedList<T> GetSub(int index_1, int index_2);

    void Size();
};
#include "linked_list_impl.h"
#endif // LAB2_3_LINKED_LIST_H
