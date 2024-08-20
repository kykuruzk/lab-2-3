#ifndef LAB2_3_LIST_SEQUENCE_H
#define LAB2_3_LIST_SEQUENCE_H

#include "../Checker/IndexOutOfRange.h"
#include "../Checker/errors.h"
#include "../classes/ComplexNumber.h"
#include "../linked_list/linked_list.h"
#include "../sequence/sequence.h"

using namespace std;

template<class T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T> linked_list;

public:
    explicit ListSequence(const LinkedList<T>& _linked_list);

    ListSequence(const ListSequence<T>& _list_sequence);

    ListSequence(int size, T* data);

    explicit ListSequence(int size);

    ListSequence() = default;

    int GetSize() const override;

    T GetElement(int index) const override;

    T GetLast() const override;

    T GetFirst() const override;

    void Replace(T element, int index) override;

    void Append(T element) override;

    void Prepend(T element) override;

    void Insert(T element, int index) override;

    void Resize(int new_size);

    void Swap(int index_1, int index_2) override;

    void Concat(ListSequence<T>& copy);

    ListSequence<T> GetSub(int a, int b);

};

#include "list_sequence_impl.h"

#endif //LAB2_3_LIST_SEQUENCE_H
