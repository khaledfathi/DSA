/********************
 * File : list.hpp
 * Namespace : dsa 
 * Created : Wed Jan 15 2025
 * Modified : Wed Jan 15 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * Linked List Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION 
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM 
********************/
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <initializer_list>

namespace dsa {
    template<typename T>
    class List{
    private: 
        class Node {
            public: 
               T value;  
               Node *next= NULL; 
        };
        size_t size = 0; 
        Node *head_ptr = NULL; 
        Node *tail_ptr = NULL; 
    public: 
        List(); 
        List(const std::initializer_list<T>& list);
        List<T>& operator =(const std::initializer_list<T>& list);
        bool isEmpty() const; 
        void pushBack (T value); 
        void pushFront (T value); 
        T first () const;
        T last () const;
        void remove (int index); 
        void display (); 
    };
}

#include "../src/list.cpp"
#endif // LIST_HPP
