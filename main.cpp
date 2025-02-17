/********************
 * File : main.cpp
 * Namespace : 
 * Created : Mon Feb 17 2025
 * Modified : Mon Feb 17 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * main entry for testing data structure
********************/


#include <iostream>
#include "./inc/array.hpp"
#include "./inc/list.hpp"
#include "./inc/d_list.hpp"
#include "./inc/stack_array.hpp"

using namespace dsa;


int main()
{
    auto st = StackArray<int, 5>();  
    // st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    std::cout << st.peek(0) << std::endl; 
}