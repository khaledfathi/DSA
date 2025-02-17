/********************
 * File : array.hpp
 * Namespace : dsa
 * Created : Tue Jan 7 2025
 * Modified : Mon Feb 17 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * Array Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM
********************/
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stddef.h>         //used for : size_t
#include <initializer_list> // used for : initializer_list

namespace dsa
{
    template <typename T, int Size>
    class Array
    {
    private:
        /**
         * @brief pointer used to point to created array in heap
         *
         */
        T *arr = nullptr;
        /**
         * @brief size of array
         *
         */
        size_t _size = 0;
        /**
         * @brief length of element that inserted to array -
         * default is 0
         */
        size_t _length = 0;

    public:
        /**
         * @brief Construct a new Array object
         *
         * @param size size of array to be allocated into heap
         */
        Array();
        /**
         * @brief Construct a new Array object
         *
         * @param list  initilizer list , i.e Array<int, 10> x = {2,5,6,7}
         */
        Array(std::initializer_list<T> list);
        
        /**
         * @brief Construct , Copy another Array 
         * 
         * @param Array array to be coped 
         */
        Array(Array<T,Size> &array);
        /**
         * @brief Destroy the Array object - free heap
         *
         */
        ~Array();
        /**
         * @brief get length of array - (how many element registerd in the array)
         *
         * @return size_t length of array
         */
        size_t length() const;
        /**
         * @brief get element by it's index
         *
         * @param index
         * @return T element
         */
        T &get(int index) const;
        /**
         * @brief Find the index of element
         *
         * @param element the element to be find
         * @return size_t - index value
         */
        int find(T element) const;
        /**
         * @brief get the first element from array
         *
         * @return T element
         */
        T first() const;
        /**
         * @brief get the last element from array
         *
         * @return T element
         */
        T last() const;
        /**
         * @brief add new element to array
         *
         * @param element the element to be added
         */
        void add(T element);
        /**
         * @brief insert element in specific index into array
         *
         * @param index  position to insert element to it
         * @param element element to be inserted
         */
        void insert(size_t index, T element);
        /**
         * @brief remove element from array
         *
         * @param index index point to element to be deleted
         */
        void remove(size_t index);
        /**
         * @brief replace element depend on its index
         *
         * @param index position to be replaced
         * @param element element to be replaced
         */
        void replace(size_t index, T element);
        /**
         * @brief reverse array  , i.e [1,2,3] = [2,1,3]
         */
        void reverse();
        /**
         * @brief merge two arrays into single array -
         * the full size of new array = to sum of length of two arrays
         * @param array array to be merged with current array
         * @return Array<T, Size>& reference to new array
         */
        Array<T, Size> &merge(Array<T, Size> &array);
        /**
         * @brief right shift array , i.e [1,2,3] = [1,2]
         *
         */
        void rightShift();
        /**
         * @brief rotate right , i.e [1,2,3,4,5] = [5,1,2,3,4]
         *
         */
        void rightRotate();
        /**
         * @brief left shift array , i.e [1,2,3] = [2,3]
         *
         */
        void leftShift();
        /**
         * @brief rotate right , i.e [1,2,3,4,5] = [2,3,4,5,1]
         *
         */
        void leftRotate();
        /**
         * @brief clear all element from array , set length = 0
         * 
         */
        void clear();
        /**
         * @brief overload operator ==  ,compare two arrays
         *
         * @param array array to by compare with this array
         * @return true if both array is identical
         * @return false if arrays not identical
         */
        bool operator==(Array<T, Size> &array) const;
        /**
         * @brief overload operator = , Array Initilize , i.e Array<int , 10> x = {1,5,3,5}
         *
         * @param list Array initilizer
         * @return Array<T, Size>&
         */
        Array<T, Size> &operator=(std::initializer_list<T> list);
        /**
         * @brief overload operator = ,copy array 
         * 
         * @param array  array to be copied 
         * @return Array<T, Size>& 
         */
        Array<T, Size> &operator=(Array<T, Size> &array);
        /**
         * @brief call get function , to get element by index
         *
         * @param index index of element
         * @return T element
         */
        T &operator[](size_t index);
        /**
         * @brief create new array that contains two arrays , i.e ( Array<T, Size> arr_x = arr1 + arr2 )
         *
         * @param array
         * @return Array<T, Size> new array
         */
        Array<T, Size> operator+(Array<T, Size> &array);
    };
} // namespace dsa

#include "../src/array.cpp"

#endif // ARRAY_HPP
