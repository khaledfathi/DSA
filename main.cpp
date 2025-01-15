/********************
 * File : main.cpp
 * Created : Tue Jan 7 2025
 * Modified : Wed Jan 15 2025
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
    Array<int> arr1 = Array<int> (10);  
    Array<int> arr2 = Array<int> (10); 


    Array<int> arr3 = arr1 + arr2; 
    arr1.insert(2,100);
    printArray(arr1); 
    return 0;
}