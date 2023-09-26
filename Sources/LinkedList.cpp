#include "../Headers/LinkedList.h"

template <typename T>
Node<T>* Linked_list<T>::insert_first(T data){
    Node<T>* node = new Node(data);
    if(this->m_head==nullptr){
        this->m_head = node;
        this->m_tail = node;
    } else {
        node->m_link = this->m_head;
        this->m_head = node;
    }
    ++this->m_length;
    return node;
}

template <typename T>
Node<T>* Linked_list<T>::delete_first(){
    if(this->m_head==nullptr){
        std::cout << "You can't delete null.\n";
        return nullptr;
    } else if(this->m_head==this->m_tail) {
        Node<T>* deleted_node = this->m_head;
        this->m_tail = nullptr;
        this->m_head = nullptr;
        --this->m_length;
        return deleted_node;
    } else {
        Node<T>* deleted_node = this->m_head;
        Node<T>* new_head = this->m_head->m_link;
        this->m_head->m_link = nullptr;
        this->m_head = new_head;
        --this->m_length;
        return deleted_node;
    }
}

template <typename T>
Node<T>* Linked_list<T>::insert_last(T x){
    Node<T>* node = new Node(x);
    if(this->m_head==nullptr){
        this->m_head = node;
        this->m_tail = node;
    } else {
        this->m_tail->m_link = node;
        this->m_tail = node;
    }
    ++this->m_length;
    return node;
}

template <typename T>
Node<T>* Linked_list<T>::delete_last(){
    if(this->m_tail==nullptr){
        std::cout << "You can't delete null.\n";
        return nullptr;
    } else if(this->m_tail==this->m_head) {
        Node<T>* deleted_node = this->m_tail;
        this->m_tail = nullptr;
        this->m_head = nullptr;
        --this->m_length;
        return deleted_node;
    } else {
        Node<T>* deleted_node = this->m_tail;
        Node<T>* current = this->m_head;
        for(int i{0}; i<this->m_length-2; ++i)
            current = current->m_link;
        this->m_tail = current;
        this->m_tail->m_link = nullptr;
        current->m_link = nullptr;
        --this->m_length;
        return deleted_node;
    }
}


template <typename T>
void Linked_list<T>::set_first(T x){
    if(this->m_head==nullptr){
        std::cout << "Head pointer is null.\n";
        return;
    }
    this->m_head->m_data = x;
}

template <typename T>
void Linked_list<T>::set_last(T x){
    if(this->m_tail==nullptr){
        std::cout << "Tail pointer is null.\n";
        return;
    }
    this->m_tail->m_data = x;
}

template <typename T>
Node<T>* Linked_list<T>::get_at(int i){
    if(i<0 || i>this->m_length){
        std::cout << "Index error.\n";
        return nullptr;
    } else if(this->m_head==nullptr) {
        std::cout << "Linked list is empty";
        return nullptr;
    } else {
        Node<T>* current = this->m_head;
        for(int j{0}; j<i; ++j)
            current = current->m_link;
        return current;
    }
}

template <typename T>
void Linked_list<T>::set_at(int i, T x){
    if(i<0 || i>this->m_length){
        std::cout << "Index error or empty list.\n";
    } else {
        Node<T>* current = this->m_head;
        for(int j{0}; j<i; ++j)
            current = current->m_link;
        current->m_data = x;
    }
}

template <typename T>
void Linked_list<T>::insert_at(int i, T x){
    if(i<0 || i>this->m_length){
        std::cout << "Index error.\n";
    } else if(i==0){
        this->insert_first(x);
    } else {
        Node<T>* new_node = new Node(x);
        Node<T>* current = this->m_head;
        for(int j{0}; j<i-1; ++j)
            current = current->m_link;
        new_node->m_link = current->m_link;
        current->m_link = new_node;
        ++this->m_length;
    }
}

template <typename T>
Node<T>* Linked_list<T>::delete_at(int i){
    Node<T>* current = this->m_head;
    for(int j{0}; j<i-1;++j)
        current = current->m_link;
    Node<T>* deleted_node = current->m_link;
    current->m_link = current->m_link->m_link;
    deleted_node->m_link = nullptr;
    --this->m_length;
    return deleted_node;
}

template <typename T>
void Linked_list<T>::iter_seq(){
    if(this->m_head==nullptr){
        std::cout << "The linked list is empty.\n";
    } else {
        Node<T>* current = this->m_head;
        while(current!=nullptr){
            std::cout << "(" << current->m_data << ") -> ";
            current = current->m_link;
        }
    }
    std::cout << '\n';
}