/********************
 * File : dsa_exceptions.hpp
 * Namespace : 
 * Created : Tue Jan 7 2025
 * Modified : Fri Jan 17 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 * 
 * Array Datastructure exception 
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM
********************/
#include "../../inc/exceptions/dsa_exceptions.hpp"
#include <string.h>

using namespace dsa; 

ArrayInitializerException::ArrayInitializerException(const char* msg){
    this->msg = msg; 
}

const char* ArrayInitializerException::what () const noexcept {
    return  this->msg; 
}
/* ##################################### */

ListEmptyException::ListEmptyException(const char* msg){
    this->msg = msg; 
}

const char* ListEmptyException::what () const noexcept {
    return  this->msg; 
}

/* ##################################### */

NotEnoughMemoryException::NotEnoughMemoryException(const char* msg){
    this->msg = msg; 
}

const char* NotEnoughMemoryException::what () const noexcept {
    return  this->msg;  
}