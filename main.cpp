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
    DList<int> x ;
    x.pushBack(11); 
    x.pushBack(12); 
    x.pushBack(13); 
    std::cout << x[1] << std::endl; 
    return 0;
}