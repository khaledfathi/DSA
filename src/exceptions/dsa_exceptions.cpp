/********************
 * File : dsa_exceptions.hpp
 * Namespace :
 * Created : Tue Jan 7 2025
 * Modified : Sat Mar 01 2025
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
/* ##################################### */

StackOverFlowException::StackOverFlowException(const char *msg)
{
    this->msg = msg;
}
const char *StackOverFlowException::what() const noexcept
{
    return this->msg; 
}
/* ##################################### */

StackUnderFlowException::StackUnderFlowException(const char *msg)
{
    this->msg = msg;
}
const char *StackUnderFlowException::what() const noexcept
{
    return this->msg; 
}
/* ##################################### */

StackEmptyException::StackEmptyException(const char *msg)
{
    this->msg = msg;
}
const char *StackEmptyException::what() const noexcept
{
    return this->msg; 
}
/* ##################################### */

InvalidStackPositionException::InvalidStackPositionException(const char *msg)
{
    this->msg = msg;
}
const char *InvalidStackPositionException::what() const noexcept
{
    return this->msg; 
}
/* ##################################### */

QueueEmptyException::QueueEmptyException(const char *msg)
{
    this->msg = msg;
}
const char *QueueEmptyException::what() const noexcept
{
    return this->msg; 
}
/* ##################################### */

QueueFullException::QueueFullException(const char *msg)
{
    this->msg = msg;
}
const char *QueueFullException::what() const noexcept
{
    return this->msg; 
}
/* ##################################### */