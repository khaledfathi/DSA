#include "../../inc/exceptions/list_empty_exception.hpp"

using namespace dsa; 

ListEmptyException::ListEmptyException(const char* msg){
    this->msg = msg; 
}

const char* ListEmptyException::what () const noexcept {
    return  this->msg; 
}