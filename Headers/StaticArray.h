#ifndef DATA_STRUCTURES_IMPLEMENTATION_STATICARRAY_H
#define DATA_STRUCTURES_IMPLEMENTATION_STATICARRAY_H

#include "StaticArray.h"
#include <iostream>

template<typename T, size_t S>
class StaticArray {
private:
    T m_array[S] {};
public:
    StaticArray() = default;
    size_t len() const { return S; }
    T get_at(size_t i);
    T get_first();
    T get_last();
    void set_at(size_t i, T x);
    void set_first();
    void set_last();
    void iter_seq();
};

#endif //DATA_STRUCTURES_IMPLEMENTATION_STATICARRAY_H
