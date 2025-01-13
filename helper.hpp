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

template <typename T>
void printArray(Array<T> &array)
{
    size_t len = array.length();
    std::cout << "[ ";
    for (int i = 0; i < len; i++)
        std::cout << array.get(i) << (i + 1 < len ? " , " : "");
    std::cout << " ]\n";
}

template <size_t S, typename... T>
Array<int> *generateArrayP(T... data)
{
    Array<int> *arr = new Array<int>(S);
    for (auto i : {data...})
        arr->add(i);
    return arr;
};
template <typename T, size_t S, typename... D>
Array<T> generateArray(D... data)
{
    Array<T> arr = Array<T>(S);
    for (auto i : {data...})
        arr.add(i);
    return arr;
};
#endif // HELPER_HPP