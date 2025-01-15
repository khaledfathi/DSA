/********************
 * File : array.hpp
 * Namespace : dsa
 * Created : Tue Jan 7 2025
 * Modified : Wed Jan 15 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * Array Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION 
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM 
********************/
#if !defined(ARRAY_HPP)
#define ARRAY_HPP

namespace dsa
{
   template <typename T>
   class Array {
    private: 
        /**
         * @brief pointer used to point to created array in heap 
         * 
         */
        T *arr = NULL; 
        /**
         * @brief size of array 
         * 
         */
        size_t _size; 
        /**
         * @brief length of element that inserted to array -
         * default is 0   
         */
        size_t _length = 0; 
    public : 
        /**
         * @brief Construct a new Array object
         * 
         * @param size size of array to be allocated into heap 
         */
        Array(size_t size);
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
        T get(size_t index) const; 
        /**
         * @brief Find the index of element 
         * 
         * @param element the element to be find 
         * @return size_t - index value 
         */
        size_t find(T element) const; 
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
         * @return Array<T>& reference to new array  
         */
        Array<T>& merge(Array<T>& array) ; 
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
         * @brief overload operator ==  ,compare two arrays
         * 
         * @param array array to by compare with this array  
         * @return true if both array is identical  
         * @return false if arrays not identical  
         */
        bool operator == (Array<T> &array)  const; 
        /**
         * @brief overload operator = ,assign array to varaible with type Array<T>
         * 
         * @param array array to be assignd 
         */
        void operator=( Array<T> &array); 
        /**
         * @brief overload operator += ,call merge function 
         * , to merge this array with parameter array 
         * 
         * @param array array to be merged with this array 
         */
        void operator+=( Array<T> &array); 
        /**
         * @brief call get function , to get element by index 
         * 
         * @param index index of element 
         * @return T element
         */
        T operator[](size_t index); 
        /**
         * @brief create new array that contains two arrays , i.e ( Array<T> arr_x = arr1 + arr2 )
         * 
         * @param array 
         * @return Array<T> new array 
         */
        Array<T> operator+(Array<T> &array);
   }; 
} // namespace dsa

#include "../src/array.cpp"

#endif // ARRAY_HPP
