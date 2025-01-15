/********************
 * File : array.hpp
 * Namespace : dsa
 * Created : Tue Jan 7 2025
 * Modified : Wed Jan 15 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 *
 * Array Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION 
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM 
 ********************/
#include <stddef.h>
#include <typeinfo>
#include <string>
#include "../inc/array.hpp"

using namespace dsa;

template <typename T>
Array<T>::Array(size_t size)
{
    this->_size = size;
    arr = new T[_size];
    if (arr == NULL)
        std::cout << "There's no Heap space to create this array !";
}
template <typename T>
Array<T>::~Array()
{
    delete[] this->arr;
}

template <typename T>
size_t Array<T>::length() const
{
    return this->_length;
}

template <typename T>
T Array<T>::get(size_t index) const
{
    if (index <= this->_length - 1)
        return this->arr[index];
    else
        throw std::out_of_range("wrong index [" + std::to_string(index) + "]  | current length is [" + std::to_string(this->_length) + "]\n");
}

template <typename T>
size_t Array<T>::find(T element) const
{
    for (int i = 0; i < this->_length; i++)
        if (element == arr[i])
            return i;
    return -1;
}

template <typename T>
T Array<T>::first() const
{
    return get(0);
}
template <typename T>
T Array<T>::last() const
{
    return get(this->_length - 1);
}

template <typename T>
void Array<T>::add(T element)
{
    if (this->_length < this->_size)
        arr[this->_length++] = element;
}

template <typename T>
void Array<T>::insert(size_t index, T element)
{
    if (index > _length - 1)
        throw std::out_of_range("wrong index [" + std::to_string(index) + "] | current length is [" + std::to_string(this->_length) + "]\n");
    if (this->_length < this->_size)
    {
        for (int i = this->_length - 1; i >= 0; i--)
        {
            std::cout << i << std::endl;
            if(i != index)
                this->arr[i+1] =this->arr[i];
            else{
                this->arr[i+1]= this->arr[i]; 
                this->arr[i] = element; 
                break; 
            } 
        }
    }
}

template <typename T>
void Array<T>::remove(size_t index)
{
    if (index < this->_length)
    {
        for (index; index < this->_length; index++)
            if (index + 1 < this->_length)
                this->arr[index] = this->arr[index + 1];
        this->_length--;
    }
    else
    {
        throw std::out_of_range("wrong index [" + std::to_string(index) + "] | current length is [" + std::to_string(this->_length) + "]\n");
    }
}

template <typename T>
void Array<T>::replace(size_t index, T element)
{
    if (index <= this->_length - 1)
        this->arr[index] = element;
    else
        throw std::out_of_range("wrong index [" + std::to_string(index) + "]  | current length is [" + std::to_string(this->_length) + "]\n");
}

/* this version of reverse() is not efficient */
// template <typename T>
// void Array<T>::reverse()
// {
//     Array<T> *newArray = new Array<T>(this->_size);
//     size_t newArrayIndex = 0;
//     for (int i = this->_length - 1; i >= 0; i--)
//     {
//         newArray->add(this->arr[i]);
//     }
//     for (int i = 0; i < this->_length; i++)
//     {
//         this->arr[i] = newArray->get(i);
//     }
//     free(newArray);
// }

template <typename T>
void Array<T>::reverse()
{
    int i = 0, j = this->_length - 1;
    for (i; i < j;)
        std::swap(this->arr[i++], this->arr[j--]);
}

template <typename T>
Array<T> &Array<T>::merge(Array<T> &array)
{
    size_t newSize = array.length() + this->_length;
    this->_size = newSize;
    T *newArr = new T[newSize];
    for (size_t i = 0; i < this->_length; i++)
    {
        newArr[i] = this->arr[i];
    }
    for (size_t i = 0; i < array.length(); i++)
    {
        newArr[i + this->_length] = array.get(i);
    }
    this->_length = newSize;
    delete[] arr;
    this->arr = newArr;
    return *this;
}

template <typename T>
void Array<T>::leftShift()
{
    if (this->_length > 0)
        this->remove(0);
}

template <typename T>
void Array<T>::leftRotate()
{
    if (this->_length > 0)
    {
        T firstElement = this->arr[0];
        this->remove(0);
        this->add(firstElement);
    }
}

template <typename T>
void Array<T>::rightShift()
{
    if (this->_length > 0)
        this->rightRotate();
    this->remove(0);
}

template <typename T>
void Array<T>::rightRotate()
{
    if (this->_length > 0)
    {
        T lastElement = this->arr[this->_length - 1];
        for (int i = this->_length - 1; i > 0; i--)
        {
            this->arr[i] = this->arr[i - 1];
        }
        this->arr[0] = lastElement;
    }
}

template <typename T>
bool Array<T>::operator==(Array<T> &array) const
{
    if (this->_length == array.length())
    {
        for (int i = 0; i < this->_length; i++)
        {
            if (this->arr[i] != array.get(i))
                return false;
        }
        return true;
    }
    return false;
}

template <typename T>
void Array<T>::operator=(Array<T> &array)
{
    this->_length = 0;
    this->_size = array.length();
    for (size_t i = 0; i < array.length(); i++)
    {
        this->add(array.get(i));
    }
}

template <typename T>
void Array<T>::operator+=(Array<T> &array)
{
    this->merge(array);
}

template <typename T>
T Array<T>::operator[](size_t index)
{
    return this->get(index);
}

template <typename T>
Array<T> Array<T>::operator+(Array<T> &array)
{
    size_t newSize = array.length() + this->_length;
    Array<T> newArray = Array<T>(newSize);
    for (size_t i = 0; i < this->_length; i++)
    {
        newArray.add(this->arr[i]);
    }
    for (size_t i = 0; i < array.length(); i++)
    {
        newArray.add(array.get(i));
    }
    return newArray;
}