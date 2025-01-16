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
#include "./inc/list.hpp"

using namespace dsa;

int main()
{

    List<int> x = {0,1,2,3,4};
    x.remove(4); 
    x.display(); 
    return 0; 
}