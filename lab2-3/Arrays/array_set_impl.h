#ifndef LAB2_3_ARRAY_SET_IMPL_H
#define LAB2_3_ARRAY_SET_IMPL_H
#include "array_set.h"
#include <algorithm>  // для std::find, std::sort
#include <stdexcept>  // для std::out_of_range

template<class T>
void ArraySet<T>::Add(T element) {
    if (!Contains(element)) {
        set.push_back(element);
    }
}

template<class T>
void ArraySet<T>::Remove(T element) {
    auto it = std::find(set.begin(), set.end(), element);
    if (it != set.end()) {
        set.erase(it);
    }
}

template<class T>
bool ArraySet<T>::Contains(T element) const {
    return std::find(set.begin(), set.end(), element) != set.end();
}

template<class T>
int ArraySet<T>::GetSize() const {
    return set.size();
}

template<class T>
bool ArraySet<T>::IsEmpty() const {
    return set.empty();
}

template<class T>
void ArraySet<T>::Clear() {
    set.clear();
}

template<class T>
T ArraySet<T>::GetAny() const {
    if (IsEmpty()) {
        throw std::out_of_range("Set is empty");
    }
    return set[0];
}

template<class T>
ArraySet<T> ArraySet<T>::Intersection(const ArraySet<T>& other) const {
    ArraySet<T> result;
    for (const T& element : set) {
        if (other.Contains(element)) {
            result.Add(element);
        }
    }
    return result;
}

template<class T>
ArraySet<T> ArraySet<T>::Union(const ArraySet<T>& other) const {
    ArraySet<T> result = *this;
    for (const T& element : other.set) {
        result.Add(element);
    }
    return result;
}

template<class T>
ArraySet<T> ArraySet<T>::Difference(const ArraySet<T>& other) const {
    ArraySet<T> result;
    for (const T& element : set) {
        if (!other.Contains(element)) {
            result.Add(element);
        }
    }
    return result;
}

template<class T>
ArraySet<T> ArraySet<T>::SymmetricDifference(const ArraySet<T>& other) const {
    ArraySet<T> result = this->Difference(other);
    ArraySet<T> otherDiff = other.Difference(*this);
    return result.Union(otherDiff);
}

template<class T>
bool ArraySet<T>::IsSubsetOf(const ArraySet<T>& other) const {
    for (const T& element : set) {
        if (!other.Contains(element)) {
            return false;
        }
    }
    return true;
}

template<class T>
bool ArraySet<T>::IsProperSubsetOf(const ArraySet<T>& other) const {
    return IsSubsetOf(other) && (GetSize() < other.GetSize());
}

template<class T>
bool ArraySet<T>::Equals(const ArraySet<T>& other) const {
    return IsSubsetOf(other) && other.IsSubsetOf(*this);
}

template<class T>
bool ArraySet<T>::Intersects(const ArraySet<T>& other) const {
    for (const T& element : set) {
        if (other.Contains(element)) {
            return true;
        }
    }
    return false;
}

template<class T>
template<typename Func>
ArraySet<T> ArraySet<T>::Map(Func func) const {
    ArraySet<T> result;
    for (const T& element : set) {
        result.Add(func(element));
    }
    return result;
}

template<class T>
template<typename Func>
ArraySet<T> ArraySet<T>::Filter(Func func) const {
    ArraySet<T> result;
    for (const T& element : set) {
        if (func(element)) {
            result.Add(element);
        }
    }
    return result;
}

template<class T>
template<typename Func, typename U>
U ArraySet<T>::Reduce(Func func, U init) const {
    U result = init;
    for (const T& element : set) {
        result = func(result, element);
    }
    return result;
}

template<class T>
T ArraySet<T>::GetElement(int index) const {
    if (index < 0 || index >= GetSize()) {
        throw std::out_of_range("Index out of range");
    }
    return set[index];
}
#endif
