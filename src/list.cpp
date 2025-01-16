/********************
 * File : list.hpp
 * Namespace : dsa 
 * Created : Wed Jan 15 2025
 * Modified : Wed Jan 15 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * Linked List Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION 
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM 
********************/

#include "../inc/list.hpp"
#include "../inc/exceptions/list_empty_exception.hpp"

using namespace dsa;

template<typename T>
List<T>::List(){}

template<typename T>
List<T>::List(const std::initializer_list<T>& list){
    for(auto i : list){
        this->pushBack(i); 
    }
}

template<typename T>
bool List<T>::isEmpty()const{
    return size == 0; 
}

template<typename T>
void List<T>::pushBack (T value){
    Node* node = new Node; 
    node->value = value; 
    if(size == 0 ) 
        this->head_ptr = this->tail_ptr = node;  
    else 
        this->tail_ptr->next = node; 
        this->tail_ptr = node; 
    this->size++; 
}

template<typename T>
void List<T>::pushFront (T value){
    Node* node = new Node; 
    node->value = value; 
    if (this->size == 0){
        this->head_ptr = this->tail_ptr = node;  
    }else{
       node->next = head_ptr;  
       head_ptr = node; 
    }
    this->size++; 
}

template<typename T>
T List<T>::first() const{
    if(head_ptr == NULL)
        throw ListEmptyException("List is Empty !"); 
    return this->head_ptr->value; 
}

template<typename T>
T List<T>::last() const{
    if(head_ptr == NULL)
        throw ListEmptyException("List is Empty !"); 
    return this->tail_ptr->value; 
}

template<typename T>
void List<T>::remove (int index){
    if(this->size == 0 || index > this->size-1) 
        throw std::out_of_range("Wrong List index [" + std::to_string(index) +"]");
    Node *previous= NULL ;
    for (int i = 0; i < index; i++)
    {
        if (previous == NULL)
            previous = head_ptr; 
        else 
            previous = previous->next; 
    }
    if (previous == NULL){ //no previous so delete first element in the list 
        Node* removed = head_ptr; 
        if(removed->next == NULL){
            delete removed; 
            head_ptr = NULL; 
        }else {
            head_ptr = removed->next; 
            delete removed; 
        }
    }else {
        Node* removed = previous->next; 
        if(removed !=NULL)
            previous->next = removed->next; 
        else
            delete removed; 
    }
}

template<typename T>
void List<T>::display (){
    Node *head = this->head_ptr; 
    while (head!= NULL)
    {
        std::cout << head->value << std::endl; 
        head = head->next; 
    }
}
