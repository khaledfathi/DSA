/********************
 * File : main.cpp
 * Created : Tue Jan 7 2025
 * Modified : Mon Jan 13 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * main entry for testing data structure 
********************/

#include <iostream>
#include "./helper.hpp"
#include "./inc/array.hpp"

using namespace dsa;

int main()
{
    Array<std::string> arr1 = generateArray<std::string , 10>("khaled","ali","kamal","amira","mona","sayed","saeed","karim","amr");
    // Array<std::string> arr1 = Array<std::string>(10);

    printArray(arr1); 
    print(arr1.last()); 
    // printArray(arr1); 
    return 0;
}