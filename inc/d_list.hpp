/********************
 * File : d_list.hpp
 * Namespace :
 * Created : Wed Jan 15 2025
 * Modified : Tue Jan 21 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 *
 * DList (Double Linked List) Datastructure template
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
    class Node
    {
    public:
        T value;
        Node *previous = NULL;
        Node *next = NULL;
    };
    int size = 0;
    Node *head_ptr = NULL;
    Node *tail_ptr = NULL;

public:
    DList();
    DList(const DList<T> &list); // copy constructor
    DList(const std::initializer_list<T> list); // initilizer i.e List<int> list =  { 1 ,4, 6, 7 }
    ~DList();
    T &get(int index) const;
    void *const head() const;
    int length() const;
    bool isEmpty() const;
    void pushBack(T value);
    void pushFront(T value);
    T first() const;
    T last() const;
    void remove(int index);
    void clear();
    void insert(int index, T element);
    int find(T element) const;
    DList<T> &merge(const DList<T> &list);
    void reverse();
    DList<T> &operator=(const std::initializer_list<T> list); // same as inittializer constuctor
    DList<T> &operator=(const DList<T> &list);
    T &operator[](int index) const;
    DList<T> operator+(const DList<T> &list) const;
    DList<T> &operator+=(const DList<T> &list);
private:
    void insertNewNode(Node *previous, T element);
};
#include "../src/d_list.cpp"
#endif // D_LISD_HPP
