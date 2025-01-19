/********************
 * File : list.hpp
 * Namespace : 
 * Created : Wed Jan 15 2025
 * Modified : Sun Jan 19 2025
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
        /**
         * @brief nested class 'Node' for linked list
         * 
         */
        class Node
        {
        public:
            T value;
            Node *next = NULL;
        };
        /**
         * @brief list size 
         * 
         */
        int size = 0;
        /**
         * @brief head pointer , point to first element in the list
         * 
         */
        Node *head_ptr = NULL;
        /**
         * @brief tail pointer , point to last element in the list
         * 
         */
        Node *tail_ptr = NULL;

    public:
        /**
         * @brief Construct a new List object
         * 
         */
        List();
        /**
         * @brief Copy Construct  
         * 
         * @param list  list to be copied 
         */
        List(const List<T> &list);                                // copy constructor
        /**
         * @brief copy Construct for initializer list 
         * 
         * @param list  list to be copied 
         */
        List(const std::initializer_list<T> list);               // initilizer i.e List<int> list =  { 1 ,4, 6, 7 }
        /**
         * @brief get element by index
         * 
         * @param index index of element 
         * @return T& element that been found 
         */
        T &get(int index) const;
        /**
         * @brief list head pointer
         * 
         * @return void* const  
         */
        void *const head() const;
        /**
         * @brief get the size of this list
         * 
         * @return int 
         */
        int length() const;
        /**
         * @brief check if there's element on this list 
         * 
         * @return true for empty 
         * @return false if not empty  
         */
        bool isEmpty() const;
        /**
         * @brief push element at the end of the list 
         * 
         * @param value element to be pushed   
         */
        void pushBack(T value);
        /**
         * @brief push element at the begining of the list
         * 
         * @param value element to be pushed   
         */
        void pushFront(T value);
        /**
         * @brief get first element in this list
         * 
         * @return T 
         */
        T first() const;
        /**
         * @brief get last element in this list
         * 
         * @return T 
         */
        T last() const;
        /**
         * @brief remove element from the list 
         * 
         * @param index  index of element to be deleted
         */
        void remove(int index);
        /**
         * @brief delete all elements in the list
         * 
         */
        void clear();
        
        /**
         * @brief insert element in specific position in this list
         * 
         * @param index position  
         * @param element element to be inserted  
         */
        void insert(int index, T element);
        /**
         * @brief find index of an element in this list 
         * 
         * @param element target element  
         * @return int index of element or -1 if element is not found  
         */
        int find(T element) const;
        /**
         * @brief merge a list with this list 
         * 
         * @param list list to be added to this list
         * @return List<T>& 
         */
        List<T> &merge(const List<T> &list);
        /**
         * @brief reverse this list
         * 
         */
        void reverse();
        /**
         * @brief overload operator = , initialize new list
         * 
         * @param list initializer list , { } 
         * @return List<T>& 
         */
        List<T> &operator=(const std::initializer_list<T> list); // same as inittializer constuctor
        /**
         * @brief overload operator = , copy list  
         * 
         * @param list list to be coped 
         * @return List<T>& 
         */
        List<T> &operator=(const List<T> &list); 
        /**
         * @brief overload operator [] , get element by index
         * 
         * @param index 
         * @return T& 
         */
        T &operator[](int index) const;
        /**
         * @brief concatenate two list into one list
         * 
         * @param list 
         * @return List<T> 
         */
        List<T> operator+(const List<T> &list) const;
    private:
        /**
         * @brief helper function for inserting Node to this list
         * 
         * @param previous previous Node 
         * @param element element to be added 
         */
        void insertNewNode(Node *previous, T element);
    };
}

#include "../src/list.cpp"
#endif // LIST_HPP