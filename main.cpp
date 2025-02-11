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
#include "./inc/d_list.hpp"
using namespace dsa;


int main()
{
    DList<int> x = {1,2,3,4} ;
    DList<int> y = {1,2,3,4} ;

    x+=y; 
    for (int i = 0; i < x.length(); i++) std::cout<< x[i] << std::endl; 
    
    return 0;
}