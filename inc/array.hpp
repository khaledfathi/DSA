/********************
 * File : array.hpp
 * Created : Tue Jan 7 2025
 * Modified : Mon Jan 13 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * Description : Array Datastructure template
********************/
#if !defined(ARRAY_HPP)
#define ARRAY_HPP

namespace dsa
{
   template <typename T>
   class Array {
    private: 
        T *arr = NULL; 
        size_t _size; 
        size_t _length = 0; 
        void swap (T &a, T &b ); 
    public : 
        Array(size_t size);
        ~Array();
        size_t length() const; 
        T get(size_t index) const; 
        size_t find(T element) const; 
        T first() const; 
        T last() const; 
        void add(T element); 
        void insert(size_t index, T element); 
        void remove(size_t index); 
        void replace(size_t index, T element); 
        void reverse(); 
        Array<T>& merge(Array<T>& array) ; 
        void rightShift(); 
        void rightRotate(); 
        void leftShift(); 
        void leftRotate(); 
        Array<T>& getUnion(); 
        Array<T>& getIntersection(); 
        Array<T>& getDifference(); 

        bool operator == (Array<T> &array)  const; 
        void operator=( Array<T> &array); 
        void operator+=( Array<T> &array); 
        T operator[](size_t index); 
        Array<T> operator+(Array<T> &array);
   }; 
} // namespace dsa

#include "../src/array.cpp"

#endif // ARRAY_HPP
