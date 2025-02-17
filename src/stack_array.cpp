/********************
 * File : stack_array.cpp
 * Namespace : dsa 
 * Created : Mon Feb 17 2025
 * Modified : Mon Feb 17 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * Stack (Stack Array) Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM
********************/
#include "../inc/stack_array.hpp"
#include "../inc/exceptions/dsa_exceptions.hpp"

using namespace dsa ; 

template<typename T , int S>
StackArray<T, S>::StackArray(){
   arr = new T[S];  
}
template<typename T , int S>
StackArray<T, S>::~StackArray(){
    delete arr; 
}

template<typename T , int S>
void StackArray<T,S>::push (T value){
    if(isFull())
        throw StackOverFlowException("trying to push element while stack is full"); 
    else
        arr[++top] = value; 
}

template<typename T , int S>
T StackArray<T,S>::pop (){
    if(isEmpty())
        throw StackUnderFlowException("trying to pop element while stack is empty"); 
    else 
        return arr[top--]; 
}

template<typename T , int S>
bool StackArray<T,S>::isFull (){
    return top == size-1; 
}

template<typename T , int S>
bool StackArray<T,S>::isEmpty(){
    return top == -1; 
}

template<typename T , int S>
T StackArray<T,S>::stackTop(){
    if (!isEmpty())
        return arr[top]; 
    else 
        throw StackEmptyException("trying to access stack top while it's empty");
}

template<typename T , int S>
T StackArray<T,S>::peek(int position){
    if((top-position+1) < 0 || position <= 0)
        throw InvalidStackPositionException("Peek Position is not exist"); 
    else 
        return arr[top-position+1]; 
}