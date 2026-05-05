#pragma once

#include "iterator.h"
#include <initializer_list>
#include <iostream>

template<typename T>
class set;

template<typename T>
set<T> operator+(const set<T>& s1, const set<T>& s2);

template<typename T>
set<T> operator*(const set<T>& s1, const set<T>& s2);

template<typename T>
set<T> operator/(const set<T>& s1, const set<T>& s2);

template<typename T>
std::ostream& operator<<(std::ostream& os, const set<T>& b);

template<typename T>
class set {
private:
    T* data;
    int dataSize;

public:
    // SPECIAL MEMBER FUNCTIONS //
    set();
    set(const set<T>& s);
    set(set<T>&& s) noexcept;
    explicit set(std::initializer_list<T> l);
    ~set();

    // FUNCTIONS //
    void clear();
    int getLength() const;
    bool contains(const T& elem) const;
    void add(const T& elem);
    void remove(const T& elem);
    T* toArray() const;

    // OPERATORS BASE FUNCTIONS //
    set<T>& unite(const set<T>& s);
    set<T>& intersection(const set<T>& s);
    set<T>& subtract(const set<T>& s);
    
    // REWRITING OPERATORS //
    set<T>& operator=(const set<T>& list);
    set<T>& operator +=(const set<T>& s);
    set<T>& operator *=(const set<T>& s);
    set<T>& operator /=(const set<T>& s);
    friend set<T> operator+ <>(const set<T>& s1, const set<T>& s2);
    friend set<T> operator* <>(const set<T>& s1, const set<T>& s2);
    friend set<T> operator/ <>(const set<T>& s1, const set<T>& s2);
    friend std::ostream& operator<< <>(std::ostream& os, const set<T>& b);

    // ITERATOR //
    Iterator<T> iteratorBegin() const;
    Iterator<T> iteratorEnd() const;
};

#include "setContainer.cpp"
