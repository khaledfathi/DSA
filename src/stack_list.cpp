/********************
 * File : stack_list.cpp
 * Created : Wed Feb 19 2025
 * Modified : Sun Feb 23 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * Stack (Stack Array) Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM
********************/
#include "../inc/stack_list.hpp"
#include "../inc/exceptions/dsa_exceptions.hpp"

using namespace dsa;


template <typename T>
void StackList<T>::push(T value)
{
    arr.pushFront(value); 
}

template <typename T>
T StackList<T>::pop()
{
    T value = arr[0]; 
    arr.remove(0); 
    return value; 
}


template <typename T>
bool StackList<T>::isEmpty()
{
    return arr.isEmpty(); 
}

template <typename T>
T StackList<T>::stackTop()
{
    if(arr.isEmpty())
        throw StackEmptyException("trying to access stack top while it's empty"); 
    return arr[0]; 
}

template <typename T>
T StackList<T>::peek(int position)
{
}