/********************
 * File : d_list.cpp
 * Namespace :
 * Created : Wed Jan 15 2025
 * Modified : Tue Jan 21 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 *
 * DList (Double Linked List) Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM
 ********************/
#include "../inc/d_list.hpp"
#include "../inc/exceptions/dsa_exceptions.hpp"

template<typename T>
DList<T>::DList(){ }
template<typename T>
DList<T>::DList(const std::initializer_list<T> list){

}
template<typename T>
DList<T>::~DList(){
    clear(); 
}

template<typename T>
T & DList<T>::get(int index) const{
    if(index > size -1)
        throw std::out_of_range("index ["+std::to_string(index)+"] out of range | list size is "+std::to_string(size) );
    Node *head = NULL; 
    for (int i = 0; i <= index; i++)
    {
        if(head == NULL) 
            head = head_ptr;
        else 
            head = head->next;
    }
    return head->value; 
}

// void *const head() const;
// int length() const;
// bool isEmpty() const;
template<typename T>
void DList<T>::pushBack(T value){
    Node *node = new Node; 
    if(node == NULL)
        throw NotEnoughMemoryException("insufficient memory"); 
    node->value = value; 
    if(tail_ptr == NULL){
        head_ptr = node; 
        tail_ptr = node; 
    }else{
        node->previous = tail_ptr; 
        tail_ptr->next = node; 
        tail_ptr = node; 
    }
    size++;
}
// void pushFront(T value);
// T first() const;
// T last() const;
// void remove(int index);
template<typename T>
void DList<T>::clear(){
    Node *cursor = head_ptr;
    if (cursor == NULL)
        return;
    Node *next = cursor->next;
    while (cursor != NULL)
    {
        next = cursor->next;
        delete cursor;
        cursor = next;
    }
    size = 0;
    head_ptr = tail_ptr = NULL;
}
// void insert(int index, T element);
// int find(T element) const;
// DList<T> &merge(const DList<T> &list);
// void reverse();
// List<T> &operator=(const std::initializer_list<T> list); // same as inittializer constuctor
// DList<T> &operator=(const List<T> &list);
template<typename T>
T & DList<T>::operator[](int index) const{
    return get(index); 
}
// T &operator[](int index) const;
// DList<T> operator+(const DList<T> &list) const;
// void insertNewNode(Node *previous, T element);