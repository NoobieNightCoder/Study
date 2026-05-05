#pragma once

template<typename T>
class Iterator {
private:
    T* current;
public:
    Iterator(T* p);

    Iterator<T>& operator++();

    T operator*() const;
    bool operator!=(const Iterator<T>& other) const;
};

#include "iterator.cpp"
