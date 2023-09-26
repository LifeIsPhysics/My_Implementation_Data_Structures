#ifndef DATA_STRUCTURES_IMPLEMENTATION_LINKEDLIST_H
#define DATA_STRUCTURES_IMPLEMENTATION_LINKEDLIST_H

#include "LinkedList.h"
#include <iostream>

template <typename T>
class Node{
public:
    T m_data;
    Node* m_link;

    explicit Node(T data, Node* link=nullptr) : m_data{data}, m_link{link} {}
};

template <typename T>
class Linked_list {
private:
    int m_length;
    Node<T>* m_head;
    Node<T>* m_tail;

public:
    Linked_list(){
        m_length = 0;
        m_head = nullptr;
        m_tail = nullptr;
    }
    int len(){
        return m_length;
    }
    Node<T>* insert_first(T data);
    Node<T>* delete_first();
    Node<T>* insert_last(T x);
    Node<T>* delete_last();
    void set_first(T x);
    void set_last(T x);
    Node<T>* get_at(int i);
    void set_at(int i, T x);
    void insert_at(int i, T x);
    Node<T>* delete_at(int i);
    void iter_seq();
};

#endif //DATA_STRUCTURES_IMPLEMENTATION_LINKEDLIST_H
