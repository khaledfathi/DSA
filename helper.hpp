/********************
 * File : helper.hpp
 * Created : Tue Jan 7 2025
 * Modified : Mon Jan 13 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * Some function to test data structures 
 * IT's NOT IMPORTANT
********************/

#if !defined(HELPER_HPP)
#define HELPER_HPP

#include <iostream>
#include "inc/array.hpp"

template <typename T>
void print(T value, std::string prefixStr = "")
{
    std::cout << prefixStr << " " << value << std::endl;
}

template <typename T , int Size>
void printArray(Array<T,Size> &array)
{
    size_t len = array.length();
    std::cout << "[ ";
    for (int i = 0; i < len; i++)
        std::cout << array.get(i) << (i + 1 < len ? " , " : "");
    std::cout << " ]\n";
}
#endif // HELPER_HPP