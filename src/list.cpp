/********************
 * File : list.cpp
 * Namespace : 
 * Created : Wed Jan 15 2025
 * Modified : Fri Jan 17 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * List (Linked List) Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM
********************/
#include <string>
#include "../inc/list.hpp"
#include "../inc/exceptions/dsa_exceptions.hpp"

using namespace dsa;

template <typename T>
List<T>::List() {}

template <typename T>
List<T>::List(const List<T> &list)
{
    clear();
    Node *head = (Node *)list.head(); 
    while (head != NULL)
    {
        pushBack(head->value); 
        head = head->next; 
        size++;
    }
}

template <typename T>
List<T>::List(const std::initializer_list<T> list)
{
    for (auto i : list)
    {
        pushBack(i);
    }
}

template <typename T>
List<T> & List<T>::operator=(const List<T> &list){
    clear();
    Node *head = (Node *)list.head(); 
    while (head != NULL)
    {
        pushBack(head->value); 
        head = head->next; 
        size++; 
    }
    return *this;
}

template <typename T>
T &List<T>::operator[](int index) const
{
    return get(index);
}

template <typename T>
List<T> List<T>::operator+(const List<T> &list) const
{
    List<T> newList = List<T>();
    //this list 
    Node* head = head_ptr; 
    while(head != NULL){
        newList.pushBack(head->value); 
        head = head->next; 
    }
    head = (Node*)list.head(); 
    while(head != NULL){
        newList.pushBack(head->value); 
        head = head->next; 
    }
    return newList;
}

template <typename T>
T &List<T>::get(int index) const
{
    if (index > size - 1)
        throw std::out_of_range("Wrong List index [" + std::to_string(index) + "] | List length = " + std::to_string(size));
    Node *cursor = head_ptr;
    for (int i = 0; i < index; i++)
    {
        cursor = cursor->next;
    }
    return cursor->value;
}

template <typename T>
int List<T>::length() const
{
    return size;
}

template <typename T>
bool List<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
void List<T>::pushBack(T value)
{
    Node *node = new Node;
    node->value = value;
    if (size == 0)
        head_ptr = tail_ptr = node;
    else
        tail_ptr->next = node;
    tail_ptr = node;
    size++;
}

template <typename T>
void List<T>::pushFront(T value)
{
    Node *node = new Node;
    node->value = value;
    if (size == 0)
    {
        head_ptr = tail_ptr = node;
    }
    else
    {
        node->next = head_ptr;
        head_ptr = node;
    }
    size++;
}

template <typename T>
T List<T>::first() const
{
    if (head_ptr == NULL)
        throw ListEmptyException("List is Empty !");
    return head_ptr->value;
}

template <typename T>
T List<T>::last() const
{
    if (head_ptr == NULL)
        throw ListEmptyException("List is Empty !");
    return tail_ptr->value;
}

template <typename T>
void List<T>::remove(int index)
{
    if (size == 0 || index > size - 1)
        throw std::out_of_range("Wrong List index [" + std::to_string(index) + "] | List length = " + std::to_string(size));
    Node *previous = NULL;
    Node *removed = head_ptr;
    for (int i = 0; i < index; i++)
    {
        if (previous == NULL)
            previous = head_ptr;
        else
            previous = previous->next;
    }
    if (previous == NULL)
    { // no previous so delete first element in the list
        if (removed->next == NULL)
        {
            delete removed;
            head_ptr = NULL;
        }
        else
        {
            head_ptr = removed->next;
            delete removed;
        }
    }
    else
    {
        Node *removed = previous->next;
        if (removed != NULL)
            previous->next = removed->next;
        else
            delete removed;
    }
}
template <typename T>
void List<T>::clear()
{
    Node *cursor = head_ptr;
    if(cursor == NULL) return ; 
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

template <typename T>
void List<T>::insert(int index, T element)
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
    {
        if (previous == NULL)
            previous = head_ptr;
        else
            previous = previous->next;
    }
    insertNewNode(previous, element);
}

template <typename T>
void List<T>::display() const
{
    Node *head = head_ptr;
    std::cout << "[ ";
    while (head != NULL)
    {
        std::cout << head->value;
        head = head->next;
        std::cout << (head != NULL ? " , " : "");
    }
    std::cout << " ]\n";
}

template <typename T>
int List<T>::find(T element) const
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

template <typename T>
const void *List<T>::head() const
{
    return (Node *)head_ptr;
}

template <typename T>
List<T> &List<T>::merge(const List<T> &list)
{
    size += list.length();
    tail_ptr->next = (Node *)list.head();
    return *this;
}

// template<typename T>
// void List<T>::reverse(){

// }

/* PRIVATE METHODS */
template <typename T>
void List<T>::insertNewNode(Node *previous, T element)
{
    Node *inserted = new Node;
    inserted->value = element;
    inserted->next = previous->next;
    previous->next = inserted;
}