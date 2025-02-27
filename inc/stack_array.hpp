/********************
 * File : stack_array.hpp
 * Namespace : 
 * Created : Mon Feb 17 2025
 * Modified : Thu Feb 27 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * Stack (Stack Array) Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM
********************/

#ifndef STACK_ARRAY_HPP
#define STACK_ARRAY_HPP

namespace dsa {
    template <typename T, int S>
    class StackArray {
        private : 
            /**
             * @brief the stack size 
             * 
             */
            int size = S;  
            /**
             * @brief stack top position index 
             * if -1 mean the stak is empty 
             * 
             */
            int top = -1; 
            /**
             * @brief pointer to array of T type 
             * 
             */
            T *arr; 
        public : 
            /**
             * @brief Construct a new Stack Array object
             * 
             */
            StackArray();
            /**
             * @brief Destroy the Stack Array object
             * 
             */
            ~StackArray();
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
             * @brief check if stack is full 
             * 
             * @return true  = stack is full
             * @return false  = stack is not full
             */
            bool isFull (); 
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

#include "../src/stack_array.cpp"
#endif // STACK_ARRAY_HPP
