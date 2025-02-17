#ifndef STACK_ARRAY_HPP
#define STACK_ARRAY_HPP

namespace dsa {
    template <typename T, int S>
    class StackArray {
        private : 
            int size = S;  
            int top = -1; 
            T *arr; 
        public : 
            StackArray();
            ~StackArray();
            void push (T value); 
            T pop (); 
            bool isFull (); 
            bool isEmpty(); 
            T stackTop(); 
            T peek(int position); 
    }; 
}

#include "../src/stack_array.cpp"
#endif // STACK_ARRAY_HPP
