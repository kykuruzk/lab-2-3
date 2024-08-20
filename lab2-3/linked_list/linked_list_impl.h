#ifndef LAB2_3_LINKED_LIST_IMPL_H
#define LAB2_3_LINKED_LIST_IMPL_H
#include "linked_list.h"

template<class T>
LinkedList<T>::LinkedList() = default;

template<class T>
LinkedList<T>::LinkedList(int _size, T* _data) {
    if (_size < 0) {
        throw IndexOutOfRange(WrongIndex);
    }
    for (int i = 0; i < _size; i++) {
        Append(_data[i]);
    }
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& array) {
    if (this == &array) {
        return *this;
    }
    for (int i = 0; i < array.GetSize(); i++) {
        Append(array.GetElement(i));
    }
    return *this;
}

template<class T>
LinkedList<T>::LinkedList(int _size) {
    if (_size < 0) {
        throw IndexOutOfRange(WrongIndex);
    }
    for (int i = 0; i < _size; i++) {
        Append(0);
    }
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& linked_list) {
    for (int i = 0; i < linked_list.GetSize(); i++) {
        Append(linked_list.GetElement(i));
    }
}

template<class T>
void LinkedList<T>::Prepend(T element) {
    List* temp = new List;
    temp->data = element;
    temp->next = nullptr;
    size++;
    if (head == nullptr) {
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

template<class T>
void LinkedList<T>::Append(T element) {
    List* temp = new List;
    temp->data = element;
    temp->next = nullptr;
    size++;
    if (head == nullptr) {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

template<class T>
void LinkedList<T>::Insert(T element, int index) {
    if (index >= GetSize() || index < 0) {
        throw IndexOutOfRange(WrongIndex);
    }
    if (index == 0) {
        Prepend(element);
        return;
    }
    if (index == size) {
        Append(element);
        return;
    }
    List* new_list = new List;
    new_list->data = element;
    List *temp, *pred = head, *pred_next;
    for (int i = 0; i < index; i++) {
        if (i + 1 == index) {
            temp = pred;
        }
        pred = pred->next;
    }
    pred_next = pred->next;
    temp->next = new_list;
    new_list->next = pred;
    size++;
}

template<class T>
T LinkedList<T>::GetFirst() const {
    if (size == 0) {
        throw IndexOutOfRange(WrongIndex);
    }
    return head->data;
}

template<class T>
T LinkedList<T>::GetLast() const {
    if (size == 0) {
        throw IndexOutOfRange(WrongIndex);
    }
    return tail->data;
}

template<class T>
int LinkedList<T>::GetSize() const {
    return size;
}

template<class T>
T LinkedList<T>::GetElement(int index) const {
    if (index >= GetSize() || index < 0) {
        throw IndexOutOfRange(WrongIndex);
    }
    List* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}

template<class T>
void LinkedList<T>::Resize(int _size) {
    if (_size < 0) {
        throw IndexOutOfRange(WrongIndex);
    }
    T* temp = new T[_size];
    int minsize = min(_size, size);
    for (int i = 0; i < minsize; i++) {
        temp[i] = GetElement(i);
    }

    List* temp2 = head;
    while (temp2 != nullptr) {
        List* tmp = temp2->next;
        delete temp2;
        temp2 = tmp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
    for (int i = 0; i < minsize; i++) {
        Append(temp[i]);
    }
    for (int i = minsize; i < _size; i++) {
        Append(0);
    }
    delete[] temp;
}

template<class T>
void LinkedList<T>::Replace(T element, int index) {
    if (index < 0 || index >= GetSize()) {
        throw IndexOutOfRange(WrongIndex);
    }
    List* temp = head;
    for (int i = 0; i < size; i++) {
        if (i == index) {
            temp->data = element;
            return;
        }
        temp = temp->next;
    }
}

template<class T>
void LinkedList<T>::Swap(int index_1, int index_2) {
    if ((index_1 >= GetSize() || index_1 < 0) || (index_2 >= GetSize() || index_2 < 0)) {
        throw IndexOutOfRange(WrongIndex);
    }
    T _1 = this->GetElement(index_1);
    T _2 = this->GetElement(index_2);
    List* temp = head;
    for (int i = 0; i < size; i++) {
        if (i == index_1) {
            temp->data = _2;
        }
        if (i == index_2) {
            temp->data = _1;
        }
        temp = temp->next;
    }
}

template<class T>
void LinkedList<T>::Concat(LinkedList<T>& copy) {
    T* final = new T[copy.size + size + 5];
    int newsize = size + copy.size;
    for (int i = 0; i < size; i++) {
        final[i] = GetElement(i);
    }
    for (int i = 0; i < copy.size; i++) {
        final[i + size] = copy.GetElement(i);
    }
    List* temp2 = head;
    while (temp2 != nullptr) {
        List* tmp = temp2->next;
        delete temp2;
        temp2 = tmp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
    for (int i = 0; i < newsize; i++) {
        Append(final[i]);
    }
    delete[] final;
}

template<class T>
LinkedList<T> LinkedList<T>::GetSub(int index_1, int index_2) {
    if ((index_1 >= GetSize() || index_1 < 0) || (index_2 >= GetSize() || index_2 < 0)) {
        throw IndexOutOfRange(WrongIndex);
    }
    T* temp = new T[index_2 - index_1 + 1];
    for (int i = index_1; i <= index_2; i++) {
        temp[i - index_1] = GetElement(i);
    }
    LinkedList<T> class_return = LinkedList<T>(index_2 - index_1 + 1, temp);
    delete[] temp;
    return class_return;
}

template<class T>
void LinkedList<T>::Size() {
    size++;
}

template<class T>
LinkedList<T>::~LinkedList() {
    List* temp = head;
    while (temp != nullptr) {
        List* tmp = temp->next;
        delete temp;
        temp = tmp;
    }
}

// Explicit instantiation for the compiler
template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<float>;


#endif
