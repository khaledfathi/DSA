/********************
 * File : main.cpp
 * Namespace : 
 * Created : Tue Jan 7 2025
 * Modified : Sun Jan 19 2025
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
    List<int> x = {0,1,2,3,4}; 
    List<int> n = {00,11,22,33,44}; 
    printList(x); 
    return 0;
}