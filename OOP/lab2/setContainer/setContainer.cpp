#include "setContainer.h"

using namespace std;

// SPECIAL MEMBER FUNCTIONS //
template <typename T>
set<T>::set() : data(nullptr), dataSize(0) {}

template <typename T>
set<T>::set(const set<T>& s) {
    dataSize = s.getLength();
    data = s.toArray();
}

template <typename T>
set<T>::set(set<T>&& s) noexcept {
    dataSize = s.dataSize;
    data = s.data;
    s.data = nullptr;
    s.dataSize = 0;
}

template <typename T>
set<T>::set(initializer_list<T> l) {
    data = nullptr;
    dataSize = 0;
    for(const T& val : l) {
        add(val);
    }
}

template <typename T>
set<T>::~set() {
    delete[] data;
}



// FUNCTIONS //
template <typename T>
void set<T>::clear() {
    delete[] data;
    data = nullptr;
    dataSize = 0;
}

template <typename T>
int set<T>::getLength() const { 
    return dataSize;
}

template <typename T>
bool set<T>::contains(const T& elem) const {
    bool hasElem = false;
    for(int i = 0; i < dataSize && !hasElem; i++) {
        if(data[i] == elem) {
            hasElem = true;
        }
    }
    return hasElem;
}

template <typename T>
void set<T>::add(const T& elem) {
    bool hasElem = false;
    for(int i = 0; i < dataSize && !hasElem; i++) {
        if(data[i] == elem) {
            hasElem = true;
        }
    }
    
    if(!hasElem) {
        T* newData = new T[++dataSize];
        for (int i = 0; i < dataSize - 1; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        data[dataSize - 1] = elem;
    }
}

template <typename T>
void set<T>::remove(const T& elem) {
    int delIndex = -1;
    for(int i = 0; i < dataSize && delIndex == -1; i++) {
        if(data[i] == elem) {
            delIndex = i;
        }
    }

    if(delIndex != -1) {
        T* newData = new T[--dataSize];
        for (int i = 0; i < delIndex; i++) {
            newData[i] = data[i];
        }
        for(int i = delIndex; i < dataSize; i++) {
            newData[i] = data[i + 1];
        }
        delete[] data;
        data = newData;
    }
}

template <typename T>
T* set<T>::toArray() const {
    T* result = new T[dataSize];
    for(int i = 0; i < dataSize; i++) {
        result[i] = data[i];
    }
    return result;
}



// OPERATORS BASE FUNCTIONS //
template <typename T>
set<T>& set<T>::unite(const set<T>& s) {
    for(int i = 0; i < s.dataSize; i++) {
        this->add(s.data[i]);
    }
    return *this;
}

template <typename T>
set<T>& set<T>::intersection(const set<T>& s) {
    T* temp = new T[dataSize];
    int size = 0;

    for(int i = 0; i < dataSize; i++) {
        if(s.contains(data[i])) {
            temp[size++] = data[i];
        }
    }

    delete[] data;
    dataSize = size;
    data = new T[size];
    for(int i = 0; i < size; i++) data[i] = temp[i];
    delete[] temp;

    return *this;
}

template <typename T>
set<T>& set<T>::subtract(const set<T>& s) {
    T* temp = new T[dataSize];
    int size = 0;

    for (int i = 0; i < dataSize; i++) {
        if (!s.contains(data[i])) {
            temp[size++] = data[i];
        }
    }

    delete[] data;
    dataSize = size;
    data = new T[dataSize];
    for (int i = 0; i < dataSize; i++) data[i] = temp[i];

    delete[] temp;
    return *this;
}



// REWRITING OPERATORS //
template <typename T>
set<T>& set<T>::operator=(const set<T>& list) {
    if (this != &list) {
        delete[] data;
        dataSize = list.getLength();
        data = list.toArray();
    }
    return *this;
}

template <typename T>
set<T>& set<T>::operator +=(const set<T>& s) {
    return this->unite(s);
}

template <typename T>
set<T>& set<T>::operator *=(const set<T>& s) {
    return this->intersection(s);
}

template <typename T>
set<T>& set<T>::operator /=(const set<T>& s) {
    return this->subtract(s);
}

template <typename T>
set<T> operator+(const set<T>& s1, const set<T>& s2) {
    set<T> newObj = s1;
    newObj.unite(s2);
    return newObj;
}

template <typename T>
set<T> operator*(const set<T>& s1, const set<T>& s2) {
    set<T> newObj = s1;
    newObj.intersection(s2);
    return newObj;
}

template <typename T>
set<T> operator/(const set<T>& s1, const set<T>& s2) {
    set<T> newObj = s1;
    newObj.subtract(s2);
    return newObj;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const set<T>& b) {
    os << "[";
    for (int i = 0; i < b.dataSize; i++) {
        os << b.data[i] << (i == b.dataSize - 1 ? "" : ", ");
    }
    os << "]";
    return os;
}


// ITERATOR //
template <typename T>
Iterator<T> set<T>::iteratorBegin() const {
    return Iterator<T>(data);
}

template <typename T>
Iterator<T> set<T>::iteratorEnd() const {
    return Iterator<T>(data + dataSize);
}
