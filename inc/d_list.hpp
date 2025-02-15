/********************
 * File : d_list.hpp
 * Namespace : 
 * Created : Wed Jan 15 2025
 * Modified : Sat Feb 15 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * List ( Double Linked List) Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM
********************/

#ifndef D_LISD_HPP
#define D_LISD_HPP
#include <initializer_list>

template <typename T>
class DList
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
        Node *previous = NULL;
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
     * @brief Construct a new DList object
     * 
     */
    DList();
    /**
     * @brief Copy Construct  
     * 
     * @param list  list to be copied 
     */
    DList(const DList<T> &list);
    /**
     * @brief copy Construct for initializer DList 
     * 
     * @param list  list to be copied 
     */
    DList(const std::initializer_list<T> list); // initilizer i.e List<int> list =  { 1 ,4, 6, 7 }
    /**
     * @brief Destroy the List object
     * 
     */
    ~DList();
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
     * @return DList<T>& 
     */
    DList<T> &merge(const DList<T> &list);
    /**
     * @brief reverse this list
     * 
     */
    void reverse();
    /**
     * @brief overload operator = , initialize new list
     * 
     * @param list initializer list , { } 
     * @return DList<T>& 
     */
    DList<T> &operator=(const std::initializer_list<T> list); // same as inittializer constuctor
    /**
     * @brief overload operator = , copy list  
     * 
     * @param list list to be coped 
     * @return List<T>& 
     */
    DList<T> &operator=(const DList<T> &list);
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
     * @return DList<T> 
     */
    DList<T> operator+(const DList<T> &list) const;
    /**
     * @brief merge a list to this list
     * 
     * @param list list to be copied for merging
     * @return DList<T> 
     */
    DList<T> &operator+=(const DList<T> &list);
    /**
     * @brief compare two lists  
     * 
     * @param list list to be compared 
     * @return true if both lists are equal 
     * @return false if both lists are not equal 
     */
    bool operator==(const DList<T> &list);
private:
    /**
     * @brief helper function for inserting Node to this list
     * 
     * @param previous previous Node 
     * @param element element to be added 
     */
    void insertNewNode(Node *previous, T element);
};
#include "../src/d_list.cpp"
#endif // D_LISD_HPP
