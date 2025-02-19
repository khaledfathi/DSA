#ifndef STACK_LIST_HPP
#define STACK_LIST_HPP
#include "../inc/list.hpp"

namespace dsa {
    template <typename T>
    class StackList {
        private : 
            int size = 0;  
            int top = -1; 
            List<T> arr = List<T>(); 
        public : 
            StackList();
            ~StackList();
            void push (T value); 
            T pop (); 
            bool isFull (); 
            bool isEmpty(); 
            T stackTop(); 
            T peek(int position); 
    }; 
}


#include "../src/stack_list.cpp"
#endif // STACK_LIST_HPP
