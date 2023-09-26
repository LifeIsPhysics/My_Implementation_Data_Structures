#include "../Headers/DynamicArray.h"
#include <cassert>

template<typename T>
void DynamicArray<T>::resize(size_t new_cap){
    if(new_cap<10)
        return;
    DynamicArray<T>* temp = new DynamicArray<T>(new_cap);
    for(size_t i{0}; i<this->m_length; ++i){
        temp->m_data[i] = m_data[i];
        ++(temp->m_length);
    }
    delete[] m_data;
    this->m_data = temp->m_data;
    this->m_length = temp->m_length;
    this->m_capacity = temp->m_capacity;
}

template<typename T>
void DynamicArray<T>::insert_last(T x){
    if(this->m_length>=this->m_capacity){
        this->resize(m_capacity*2);
    }
    this->m_data[m_length] = x;
    ++this->m_length;
}

template<typename T>
T DynamicArray<T>::delete_last(){
    assert(this->m_length>0 && "Array empty.");
    if(this->m_length<=this->m_capacity/4)
        this->resize(this->m_capacity/2);
    --this->m_length;
    return this->m_data[m_length];
}

template<typename T>
T DynamicArray<T>::get_at(size_t i){
    assert(i<this->m_length && "Out of array index.");
    return this->m_data[i];
}

template<typename T>
void DynamicArray<T>::set_at(size_t i, T x){
    assert(i<this->m_length && "Out of array index.");
    this->m_data[i] = x;
}

template<typename T>
void DynamicArray<T>::insert_first(T x){
    if(this->m_length>=this->m_capacity)
        this->resize(2*this->m_capacity);

    DynamicArray<T>* temp = new DynamicArray<T>(this->m_capacity);
    temp->m_data[0] = x;
    for(size_t i{0}; i<this->m_length; ++i){
        temp->m_data[i+1] = this->m_data[i];
        ++temp->m_length;
    }
    delete[] this->m_data;
    this->m_data = temp->m_data;
    this->m_length = temp->m_length + 1;
    this->m_capacity = temp->m_capacity;
}

template<typename T>
T DynamicArray<T>::delete_first(){
    assert(this->m_length>0 && "Array empty");
    T deleted_value = this->m_data[0];
    if(this->m_length<=this->m_capacity/4){
        this->resize(this->m_capacity/2);
    }
    DynamicArray<T>* temp = new DynamicArray<T>(this->m_capacity);
    for(size_t i{1}; i<this->m_length; ++i){ // Skip first element
        temp->m_data[i-1] = this->m_data[i];
        ++temp->m_length;
    }
    delete[] this->m_data;
    this->m_data = temp->m_data;
    this->m_length = temp->m_length;
    this->m_capacity = temp->m_capacity;
    return deleted_value;
}

template<typename T>
void DynamicArray<T>::insert_at(size_t i, T x){
    if(this->m_length>=this->m_capacity)
        this->resize(2*this->m_capacity);
    DynamicArray<T>* temp = new DynamicArray<T>(this->m_capacity);
    for(size_t j{0}; j<i; ++j){
        temp->m_data[j] = this->m_data[j];
        ++temp->m_length;
    }
    temp->m_data[i] = x;
    ++temp->m_length;
    for(size_t j{i}; j<this->m_length; ++j){
        temp->m_data[j+1] = this->m_data[j];
        ++temp->m_length;
    }
    delete[] this->m_data;
    this->m_data = temp->m_data;
    this->m_length = temp->m_length;
    this->m_capacity = temp->m_capacity;
}

template<typename T>
T DynamicArray<T>::delete_at(size_t i){
    assert(i<this->m_length && "Out of array index deletion.");
    T deleted_value = this->m_data[i];
    if(this->m_length<=this->m_capacity/4){
        this->resize(m_capacity/2);
    }
    DynamicArray<T>* temp = new DynamicArray<T>(this->m_capacity);
    for(size_t j{0}; j<i; ++j){
        temp->m_data[j] = this->m_data[j];
        ++temp->m_length;
    }
    for(size_t j{i}; j<this->m_length-1; ++j){
        temp->m_data[j] = this->m_data[j+1];
        ++temp->m_length;
    }
    delete[] this->m_data;
    this->m_data = temp->m_data;
    this->m_length = temp->m_length;
    this->m_capacity = temp->m_capacity;
    return deleted_value;
}

template <typename T>
void DynamicArray<T>::iter_seq(){
    if(this->m_length==0){
        std::cout << "[]\n";
        return;
    }
    for(size_t i{0}; i<this->m_length; ++i){
        if(i==0)
            std::cout << '[' << this->m_data[i] << ", ";
        else if(i==this->m_length-1)
            std::cout << this->m_data[i] << "]\n";
        else
            std::cout << this->m_data[i] << ", ";
    }
}