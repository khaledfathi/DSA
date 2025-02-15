/********************
 * File : main.cpp
 * Namespace : 
 * Created : Tue Jan 7 2025
 * Modified : Sat Feb 15 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * main entry for testing data structure
********************/

#include <iostream>
#include "./inc/array.hpp"
#include "./inc/list.hpp"
#include "./inc/d_list.hpp"
using namespace dsa;


int main()
{
    DList<int> x = {1,2,3,4} ;

    x.reverse(); 
    for (int i = 0; i < x.length(); i++)
    {
        std::cout << x[i] << std::endl; 
    }
    
    return 0;
}