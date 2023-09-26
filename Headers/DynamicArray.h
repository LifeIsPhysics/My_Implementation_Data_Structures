#ifndef DATA_STRUCTURES_IMPLEMENTATION_DYNAMICARRAY_H
#define DATA_STRUCTURES_IMPLEMENTATION_DYNAMICARRAY_H

#include <iostream>

template <typename T>
class DynamicArray{
private:
    size_t m_length, m_capacity;
    T* m_data;

public:
    DynamicArray(size_t capacity=10){
        m_length = 0;
        m_capacity = capacity;
        m_data = new T[capacity];
    }
    ~DynamicArray(){
        delete[] m_data;
    }
    void resize(size_t new_cap);
    size_t len() const { return m_length; }
    size_t cap() const { return m_capacity; }
    void insert_last(T x);
    T delete_last();
    T get_at(size_t i);
    void set_at(size_t i, T x);
    void insert_first(T x);
    T delete_first();
    void insert_at(size_t i, T x);
    T delete_at(size_t i);
    void iter_seq();
};

#endif //DATA_STRUCTURES_IMPLEMENTATION_DYNAMICARRAY_H
