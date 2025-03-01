/********************
 * File : queue.hpp
 * Namespace :
 * Created : Thu Feb 27 2025
 * Modified : Sat Mar 01 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 *
 * Queue (Queue Array) Datastructure template
 * Using circular queue method
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
    if (!isFull())
    {
        rear = (rear + 1) % size;
        arr[rear] = value;
    }
    else
        throw QueueFullException("trying to enqueue to queue while it is full ");
}

template <typename T , int Size> 
T QueueArray<T,Size>::dequeue (){
    if (!isEmpty())
    {
        front = (front + 1) % size;
        return arr[front];
    }
    else
        throw QueueEmptyException("trying to dequeue elemnt while Queue is empty ");
}

template <typename T , int Size> 
bool QueueArray<T,Size>::isEmpty(){
    return front == rear  ; 
}

template <typename T , int Size> 
bool QueueArray<T,Size>::isFull(){
    return ((rear + 1) % size == front);
}

template <typename T , int Size> 
T QueueArray<T,Size>::first(){
    return arr[(front+1)%Size];
}

template <typename T , int Size> 
T QueueArray<T,Size>::last(){
    return arr[rear];
}