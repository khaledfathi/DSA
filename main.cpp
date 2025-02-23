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
#include "./inc/stack_list.hpp"

using namespace dsa;


int main()
{
    StackList<int> st = StackList<int>(); 
    st.push(11); 
    st.push(12); 
    st.push(13); 
    st.push(14); 
    st.push(15); 
    st.pop(); 
    std::cout  << st.pop() << std::endl; 
    std::cout  << st.stackTop() << std::endl; 

    return 0 ; 
}