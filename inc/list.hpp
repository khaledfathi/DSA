/********************
 * File : list.hpp
 * Namespace : 
 * Created : Thu Jan 16 2025
 * Modified : Fri Jan 17 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * List (Linked List) Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM
********************/
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <initializer_list>

namespace dsa
{
    template <typename T>
    class List
    {
    private:
        class Node
        {
        public:
            T value;
            Node *next = NULL;
        };
        int size = 0;
        Node *head_ptr = NULL;
        Node *tail_ptr = NULL;

    public:
        List();
        List(const List<T> &list);                                // copy constructor
        List(const std::initializer_list<T> list);               // initilizer i.e List<int> list =  { 1 ,4, 6, 7 }
        List<T> &operator=(const std::initializer_list<T> list); // same as inittializer constuctor
        List<T> &operator=(const List<T> &list); 
        T &operator[](int index) const;
        List<T> operator+(const List<T> &list) const;
        T &get(int index) const;
        const void *head() const;
        int length() const;
        bool isEmpty() const;
        void pushBack(T value);
        void pushFront(T value);
        T first() const;
        T last() const;
        void remove(int index);
        void clear();
        void display() const;
        void insert(int index, T element);
        int find(T element) const;
        List<T> &merge(const List<T> &list);
        void reverse();

    private:
        void insertNewNode(Node *previous, T element);
    };
}

#include "../src/list.cpp"
#endif // LIST_HPP