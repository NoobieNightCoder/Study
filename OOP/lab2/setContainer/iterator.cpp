#include "iterator.h"

template<typename T>
Iterator<T>::Iterator(T* p) : current(p) {}

template<typename T>
Iterator<T>& Iterator<T>::operator++() {
    current++;
    return *this;
}

template<typename T>
T Iterator<T>::operator*() const {
    return *current;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const {
    return current != other.current;
}
