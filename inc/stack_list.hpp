/********************
 * File : stack_list.hpp
 * Namespace : 
 * Created : Wed Feb 19 2025
 * Modified : Sun Feb 23 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * Stack (Stack Array) Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM
********************/

#ifndef STACK_LIST_HPP
#define STACK_LIST_HPP
#include "../inc/list.hpp"

namespace dsa {
    template <typename T>
    class StackList {
        private : 
            List<T> arr = List<T>(); 
        public : 
            void push (T value); 
            T pop (); 
            bool isEmpty(); 
            T stackTop(); 
            T peek(int position); 
    }; 
}


#include "../src/stack_list.cpp"
#endif // STACK_LIST_HPP
