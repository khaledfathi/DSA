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

#ifndef QUEUE_ARRAY_HPP
#define QUEUE_ARRAY_HPP

namespace dsa
{
    template <typename T, int Size>
    class QueueArray
    {
    private:
        int front = -1;
        int rear = -1;
        T *arr ; 
    public:
        QueueArray (); 
        ~QueueArray (); 
        void enqueue (T value); 
        T dequeue (); 
        bool isEmpty(); 
        bool isFull(); 
        T first(); 
        T last(); 
    };

} // namespace dsa

#include "../src/queue_array.cpp"
#endif // QUEUE_ARRAY_HPP
