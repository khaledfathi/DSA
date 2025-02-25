/********************
 * File : main.cpp
 * Namespace : 
 * Created : Tue Jan 7 2025
 * Modified : Tue Feb 25 2025
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
    st.push(1); 
    st.push(2); 
    st.push(3); 
    st.push(4); 
    st.push(5); 
    std::cout  << "Top = " << st.stackTop() << std::endl; 
    std::cout << st.peek(1) << std::endl; 
    std::cout << st.peek(2) << std::endl; 
    std::cout << st.peek(3) << std::endl; 
    std::cout << st.peek(4) << std::endl; 
    std::cout << st.peek(5) << std::endl; 

    return 0 ; 
}