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
#ifndef LIST_EMPTY_HPP
#define LIST_EMPTY_HPP

#include <exception>

namespace dsa{
    /**
     * @brief Array initializer Exception
     * 
     */
    class ArrayInitializerException : public std::exception {
    private : 
        const char * msg;  
    public : 
        explicit ArrayInitializerException(const char* msg);
        const char* what () const noexcept override;
    }; 
    /**
     * @brief List Empty Exception
     * 
     */
    class ListEmptyException : public std::exception {
    private : 
        const char * msg;  
    public : 
        explicit ListEmptyException(const char* msg);
        const char* what () const noexcept override;
    }; 
    /**
     * @brief Not Enough Memory Exception
     * 
     */
    class NotEnoughMemoryException: public std::exception {
    private : 
        const char * msg;  
    public : 
        explicit NotEnoughMemoryException(const char* msg);
        const char* what () const noexcept override;
    }; 
}

#endif // LIST_EMPTY_HPP

