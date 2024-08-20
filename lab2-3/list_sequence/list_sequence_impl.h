#ifndef LAB2_3_LIST_SEQUENCE_IMPL_H
#define LAB2_3_LIST_SEQUENCE_IMPL_H
#include "list_sequence.h"

template<class T>
ListSequence<T>::ListSequence(const LinkedList<T>& _linked_list) {
    linked_list = LinkedList<T>(_linked_list);
}

template<class T>
ListSequence<T>::ListSequence(const ListSequence<T>& _list_sequence) {
    linked_list = _list_sequence.linked_list;
}

template<class T>
ListSequence<T>::ListSequence(int size, T* data) {
    linked_list = LinkedList<T>(size, data);
}

template<class T>
ListSequence<T>::ListSequence(int size) {
    linked_list = LinkedList<T>(size);
}

template<class T>
int ListSequence<T>::GetSize() const {
    return linked_list.GetSize();
}

template<class T>
T ListSequence<T>::GetElement(int index) const {
    return linked_list.GetElement(index);
}

template<class T>
T ListSequence<T>::GetLast() const {
    return linked_list.GetLast();
}

template<class T>
T ListSequence<T>::GetFirst() const {
    return linked_list.GetFirst();
}

template<class T>
void ListSequence<T>::Replace(T element, int index) {
    linked_list.Replace(element, index);
}

template<class T>
void ListSequence<T>::Append(T element) {
    linked_list.Append(element);
}

template<class T>
void ListSequence<T>::Prepend(T element) {
    linked_list.Prepend(element);
}

template<class T>
void ListSequence<T>::Insert(T element, int index) {
    linked_list.Insert(element, index);
}

template<class T>
void ListSequence<T>::Resize(int new_size) {
    linked_list.Resize(new_size);
}

template<class T>
void ListSequence<T>::Swap(int index_1, int index_2) {
    linked_list.Swap(index_1, index_2);
}

template<class T>
void ListSequence<T>::Concat(ListSequence<T>& copy) {
    linked_list.Concat(copy.linked_list);
}

template<class T>
ListSequence<T> ListSequence<T>::GetSub(int a, int b) {
    LinkedList<T> sublist = linked_list.GetSub(a, b);
    return ListSequence<T>(sublist);
}

#endif
