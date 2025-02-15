/********************
 * File : d_list.cpp
 * Namespace : 
 * Created : Wed Jan 15 2025
 * Modified : Sat Feb 15 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * List ( Double Linked List) Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM
********************/

#include <string>
#include "../inc/d_list.hpp"
#include "../inc/exceptions/dsa_exceptions.hpp"

template<typename T>
DList<T>::DList(){ }

template<typename T>
DList<T>::DList(const DList<T> &list)
{
    clear(); 
    for (int i = 0; i < list.length(); i++)
    {
        pushBack(list[i]);
    }
}
template <typename T>
DList<T>::DList(const std::initializer_list<T> list)
{
    clear(); 
    for (auto i : list)
        pushBack(i);

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
template <typename T>
void *const DList<T>::head() const
{
    return head_ptr;
}
template <typename T>
int DList<T>::length() const
{
    return size;
}
template <typename T>
bool DList<T>::isEmpty() const
{
    return size == 0;
}

template<typename T>
void DList<T>::pushBack(T value){
    Node *node = new Node; 
    if(node == NULL)
        throw NotEnoughMemoryException("insufficient memory"); 
    node->value = value; 
    if(tail_ptr == NULL){
        head_ptr = tail_ptr = node;
    }else{
        node->previous = tail_ptr; 
        tail_ptr->next = node; 
        tail_ptr = node; 
    }
    size++;
}
template <typename T>
void DList<T>::pushFront(T value)
{
    Node *node = new Node;
    if (node == NULL)
        throw NotEnoughMemoryException("insufficient memory");
    node->value = value;
    if (head_ptr == NULL)
    {
        head_ptr = tail_ptr = node;
    }
    else
    {
        node->next = head_ptr;
        head_ptr->previous = node;
        head_ptr = node;
    }
    size++;
}
template <typename T>
T DList<T>::first() const
{
    if (head_ptr == NULL)
        throw ListEmptyException("List is Empty !");
    return head_ptr->value;
}
template <typename T>
T DList<T>::last() const
{
    if (head_ptr == NULL)
        throw ListEmptyException("List is Empty !");
    return tail_ptr->value;
}

template <typename T>
void DList<T>::remove(int index)
{
    if (size == 0 || index > size - 1)
        throw std::out_of_range("Wrong List index [" + std::to_string(index) + "] | List length = " + std::to_string(size));
    Node *removed = NULL, *previous, *next;
    for (int i = 0; i <= index; i++) // find the node to be removed 
        if (removed == NULL)
            removed = head_ptr;
        else
            removed = removed->next;
    
    previous = removed->previous; 
    next = removed->next;

    if(removed == head_ptr){
        next->previous = NULL; 
        head_ptr = next;  
    }else if(removed == tail_ptr){
        previous->next = NULL;
        tail_ptr = previous; 
    }else {
        previous->next = next;
        next->previous = previous;
    }
    delete (removed);
    size--;
}
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
template<typename T>
void DList<T>::insert(int index, T element)
{
    if (index > size)
        throw std::out_of_range("Wrong List index [" + std::to_string(index) + "] | List length = " + std::to_string(size));

    if (index == 0)
    { // if index target list head
        pushFront(element);
        return;
    }
    else if (index == size)
    { // if index target list tail
        pushBack(element);
        return;
    }

    Node *previous = NULL; // used as a cursor
    for (int i = 0; i <= index - 1; i++)
        if (previous == NULL)
            previous = head_ptr;
        else
            previous = previous->next;
    insertNewNode(previous, element);
}

template <typename T>
int DList<T>::find(T element) const
{
    Node *cursor = head_ptr;
    int index = -1;
    while (cursor != NULL)
    {
        index++;
        if (cursor->value == element)
            return index;
        cursor = cursor->next;
    }
    return -1;
}
template<typename T>
DList<T> & DList<T>::merge(const DList<T> &list){
    for (int i = 0; i < list.length(); i++)
    {
        pushBack(list[i]); 
    }
    return *this;
}

template <typename T>
void DList<T>::reverse(){
    Node *cursor = head_ptr; 
    Node *temp; 
    while (cursor != NULL)
    {
        temp = cursor->next; 
        cursor->next = cursor->previous; 
        cursor->previous = temp; 
        cursor = cursor->previous;
        if(cursor != NULL && cursor->next == NULL) head_ptr = cursor; 
    }
}

template<typename T>
DList<T>& DList<T>::operator=(const std::initializer_list<T> list)
{
    clear(); 
    for (auto i : list)
        pushBack(i);
    return *this;
}

template<typename T>
DList<T> & DList<T>::operator=(const DList<T> &list)
{
    clear(); 
    for (int i = 0; i < list.length(); i++)
    {
        pushBack(list[i]);
    }
    return *this;
}

template<typename T>
T & DList<T>::operator[](int index) const{
    return get(index);
}
template <typename T>
DList<T> DList<T>::operator+(const DList<T> &list) const
{
    DList<T> newList = DList<T>();
    // this list
    Node *head = head_ptr;
    while (head != NULL)
    {
        newList.pushBack(head->value);
        head = head->next;
    }
    head = (Node *)list.head();
    while (head != NULL)
    {
        newList.pushBack(head->value);
        head = head->next;
    }
    return newList;
}
template<typename T>
DList<T> & DList<T>::operator+=(const DList<T> &list)
{
    return merge(list); 
}

template<typename T>
bool DList<T>::operator==(const DList<T> &list){
    if(this->size != list.length()) return  false ;
    Node *left_head = head_ptr; 
    Node *right_head = (Node*) list.head(); 
    for (int i=0 ; i < list.length(); i++){
        if (left_head->value != right_head->value) return false; 
        left_head = left_head->next ; 
        right_head = right_head->next;
    }
    return true ; 
}

/* PRIVATE METHODS */
template <typename T>
void DList<T>::insertNewNode(Node *previous, T element)
{
    Node *inserted = new Node;
    inserted->value = element;
    inserted->next = previous->next;
    inserted->previous = previous; 
    inserted->next->previous = inserted; 
    previous->next = inserted;
    size++;
}