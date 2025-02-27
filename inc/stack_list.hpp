/********************
 * File : stack_list.hpp
 * Namespace : 
 * Created : Wed Feb 19 2025
 * Modified : Thu Feb 27 2025
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
            /**
             * @brief Linked list of type [T] , used for storing stack elements
             * 
             */
            List<T> arr = List<T>(); 
        public : 
            /**
             * @brief push new element to the stack  
             * 
             * @param value element to be added to stack 
             */
            void push (T value); 
            /**
             * @brief pop out element from stack
             * 
             * @return T return element has been popped out
             */
            T pop (); 
            /**
             * @brief check if stack is empty 
             * 
             * @return true = stack is empty 
             * @return false = stack is not empty 
             */
            bool isEmpty(); 
            /**
             * @brief get the top element in the stack , put not popped out from the stack
             * 
             * @return T  top element of the stack 
             */
            T stackTop(); 
            /**
             * @brief get the peek value in the stack depend on the given position
             * 
             * @param position max position of stack 
             * @return T value at the position 
             */
            T peek(int position); 
    }; 
}


#include "../src/stack_list.cpp"
#endif // STACK_LIST_HPP
