#ifndef LIST_EMPTY_HPP
#define LIST_EMPTY_HPP

#include <exception>

namespace dsa{
    class ListEmptyException : public std::exception {
    private : 
        const char * msg;  
    public : 
        explicit ListEmptyException(const char* msg);
        const char* what () const noexcept override;
    }; 
}

#endif // LIST_EMPTY_HPP

