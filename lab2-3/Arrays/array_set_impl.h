#ifndef LAB2_3_ARRAY_SET_IMPL_H
#define LAB2_3_ARRAY_SET_IMPL_H
#include "array_set.h"
#include <stdexcept>  // для std::out_of_range

template<class T>
void ArraySet<T>::Add(T element) {
    if (!Contains(element)) {
        set.Append(element);
    }
}

template<class T>
void ArraySet<T>::Remove(T element) {
    for (int i =0 ; i<this->GetSize();i++) {
        if (set.GetElement(i) == element) {
            set.remove(i);
            return;
        }
    }
}

template<class T>
bool ArraySet<T>::Contains(T element) const {
    return set.IsContained(element);
}

template<class T>
int ArraySet<T>::GetSize() const {
    return set.GetSize();
}

template<class T>
bool ArraySet<T>::IsEmpty() const {
    return set.GetSize()==0;
}

template<class T>
void ArraySet<T>::Clear() {
    set = ArraySequence<T>();
}

template<class T>
T ArraySet<T>::GetAny() const {
    if (IsEmpty()) {
        throw std::out_of_range("Set is empty"); 
    }
    return set.GetElement(0);
}

template<class T>
ArraySet<T> ArraySet<T>::Intersection(const ArraySet<T>& other) const {
    ArraySet<T> result;
    for (int i =0 ; i<this->GetSize();i++) {
        if (other.Contains(set.GetElement(i))) {
            result.Add(set.GetElement(i));
        }
    }
    return result;
}

template<class T>
ArraySet<T> ArraySet<T>::Union(const ArraySet<T>& other) const {
    ArraySet<T> result = *this;
    for (int i =0 ; i<other.set.GetSize();i++) {
        result.Add(other.set.GetElement(i));
    }
    return result;
}

template<class T>
ArraySet<T> ArraySet<T>::Difference(const ArraySet<T>& other) const {
    ArraySet<T> result;
    for (int i =0 ; i<this->GetSize();i++) {
        if (!other.Contains(set.GetElement(i))) {
            result.Add(set.GetElement(i));
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
    for (int i =0 ; i<this->GetSize();i++) {
        if (!other.Contains(set.GetElement(i))) {
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
    for (int i =0 ; i<this->GetSize();i++) {
        if (other.Contains(set.GetElement(i))) {
            return true;
        }
    }
    return false;
}

template<class T>
template<typename Func>
ArraySet<T> ArraySet<T>::Map(Func func) const {
    ArraySet<T> result;
    for (int i =0 ; i<this->GetSize();i++) {
        result.Add(func(set.GetElement(i)));
    }
    return result;
}

template<class T>
template<typename Func>
ArraySet<T> ArraySet<T>::Filter(Func func) const {
    ArraySet<T> result;
    for (int i =0 ; i<this->GetSize();i++) {
        if (func(set.GetElement(i))) {
            result.Add(set.GetElement(i));
        }
    }
    return result;
}

template<class T>
template<typename Func, typename U>
U ArraySet<T>::Reduce(Func func, U init) const {
    U result = init;
    for (int i =0 ; i<this->GetSize();i++) {
        result = func(result, set.GetElement(i));
    }
    return result;
}

template<class T>
T ArraySet<T>::GetElement(int index) const {
    if (index < 0 || index >= GetSize()) {
        throw std::out_of_range("Index out of range");
    }
    return set.GetElement(index);
}
#endif
