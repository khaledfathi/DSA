/********************
 * File : main.cpp
 * Namespace : 
 * Created : Tue Jan 7 2025
 * Modified : Fri Jan 17 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * main entry for testing data structure
********************/

#include <iostream>
#include "./helper.hpp"
#include "./inc/array.hpp"
#include "./inc/list.hpp"

using namespace dsa;

int main()
{
    Array<int , 5> x = {1,2,3}; 
    x.insert(3, 10); 
    printArray(x); 




    return 0;
}