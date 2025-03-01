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
#include "./inc/queue_array.hpp"

using namespace dsa;


int main()
{
    std::cout << "Start \n"; 

    auto x = QueueArray<int, 5>(); 
    x.enqueue(1); 
    x.enqueue(2); 
    x.enqueue(3); 
    x.enqueue(4); 
    x.enqueue(5); 
    std::cout << "first = " << x.first() << std::endl; 
    std::cout << "last = " << x.last() << std::endl; 
    std::cout << "is empty = " << x.isEmpty() << std::endl; 
    std::cout << "is full = " << x.isFull() << std::endl; 
    std::cout << "Done\n"; 
    return 0 ; 
}