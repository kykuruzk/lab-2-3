#ifndef LAB2_3_ARRAY_SET_H
#define LAB2_3_ARRAY_SET_H

#include "array_sequence.h"
#include "../list_sequence/list_sequence.h"

#include <stdexcept>

template<class T>
class ArraySet {
private:
    ArraySequence<T> set;

public:
    void Add(T element);
    void Remove(T element);
    bool Contains(T element) const;
    int GetSize() const;
    bool IsEmpty() const;
    void Clear();
    T GetAny() const;
    ArraySet<T> Intersection(const ArraySet<T>& other) const;
    ArraySet<T> Union(const ArraySet<T>& other) const;
    ArraySet<T> Difference(const ArraySet<T>& other) const;
    ArraySet<T> SymmetricDifference(const ArraySet<T>& other) const;
    bool IsSubsetOf(const ArraySet<T>& other) const;
    bool IsProperSubsetOf(const ArraySet<T>& other) const;
    bool Equals(const ArraySet<T>& other) const;
    bool Intersects(const ArraySet<T>& other) const;
    template<typename Func>
    ArraySet<T> Map(Func func) const;
    template<typename Func>
    ArraySet<T> Filter(Func func) const;
    template<typename Func, typename U>
    U Reduce(Func func, U init) const;
    T GetElement(int index) const;
};




#include "array_set_impl.h"
#endif // LAB2_3_ARRAY_SET_H
