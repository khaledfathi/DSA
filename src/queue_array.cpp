/********************
 * File : queue.hpp
 * Namespace :
 * Created : Thu Feb 27 2025
 * Modified : Sat Mar 01 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 *
 * Queue (Queue Array) Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM
 ********************/

#include "../inc/queue_array.hpp"
#include "../inc/exceptions/dsa_exceptions.hpp"

using namespace  dsa; 

template <typename T , int Size> 
QueueArray<T , Size>::QueueArray(){
    arr = new T[Size]; 
}

template <typename T , int Size> 
QueueArray<T,Size>::~QueueArray (){
    delete(arr); 
}

template <typename T , int Size> 
void QueueArray<T,Size>::enqueue (T value){
    if(!isFull())
        arr[++rear] = value; 
    else 
        throw QueueFullException("trying to add elemnt to queue while it is empty "); 
}

template <typename T , int Size> 
T QueueArray<T,Size>::dequeue (){
    if(!isEmpty())
        return arr[++front]; 
    else
        throw QueueEmptyException("trying to dequeue elemnt while Queue is full "); 
}

template <typename T , int Size> 
bool QueueArray<T,Size>::isEmpty(){
    return front == rear  ; 
}

template <typename T , int Size> 
bool QueueArray<T,Size>::isFull(){
    return rear == sizeof-1; 
}

template <typename T , int Size> 
T QueueArray<T,Size>::first(){
    return arr[front+1];
}

template <typename T , int Size> 
T QueueArray<T,Size>::last(){
    return arr[rear];
}