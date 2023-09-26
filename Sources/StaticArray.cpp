#include "../Headers/StaticArray.h"
#include <cassert>

template<typename T, size_t S>
T StaticArray<T, S>::get_at(size_t i) {
    assert(i<S && "Out of array index.");
    return this->m_array[i];
}

template <typename T, size_t S>
T StaticArray<T, S>::get_first() { return this->m_array[0]; }

template <typename T, size_t S>
T StaticArray<T, S>::get_last() { return this->m_array[S-1]; }

template <typename T, size_t S>
void StaticArray<T, S>::set_at(size_t i, T x) {
    assert(i<S && "Out of array index.");
    this->m_array[i] = x;
}

template <typename T, size_t S>
void StaticArray<T, S>::set_first() { return this->m_array[0]; }

template <typename T, size_t S>
void StaticArray<T, S>::set_last() { return this->m_array[S-1]; }

template <typename T, size_t S>
void StaticArray<T, S>::iter_seq() {
    for (size_t i{0}; i < S; ++i) {
        if (i == 0)
            std::cout << "[" << m_array[i] << ", ";
        else if (i == S - 1)
            std::cout << m_array[i] << "]\n";
        else
            std::cout << m_array[i] << ", ";
    }
}