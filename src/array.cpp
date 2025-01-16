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
    delete[] arr;
}

template <typename T>
size_t Array<T>::length() const
{
    return _length;
}

template <typename T>
T Array<T>::get(size_t index) const
{
    if (index <= _length - 1)
        return arr[index];
    else
        throw std::out_of_range("wrong index [" + std::to_string(index) + "]  | current length is [" + std::to_string(_length) + "]\n");
}

template <typename T>
size_t Array<T>::find(T element) const
{
    for (int i = 0; i < _length; i++)
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
    return get(_length - 1);
}

template <typename T>
void Array<T>::add(T element)
{
    if (_length < _size)
        arr[_length++] = element;
}

template <typename T>
void Array<T>::insert(size_t index, T element)
{
    if (index > _length - 1)
        throw std::out_of_range("wrong index [" + std::to_string(index) + "] | current length is [" + std::to_string(_length) + "]\n");
    if (_length < _size)
    {
        for (int i = _length - 1; i >= 0; i--)
        {
            std::cout << i << std::endl;
            if(i != index)
                arr[i+1] =arr[i];
            else{
                arr[i+1]= arr[i]; 
                arr[i] = element; 
                break; 
            } 
        }
    }
}

template <typename T>
void Array<T>::remove(size_t index)
{
    if (index < _length)
    {
        for (index; index < _length; index++)
            if (index + 1 < _length)
                arr[index] = arr[index + 1];
        _length--;
    }
    else
    {
        throw std::out_of_range("wrong index [" + std::to_string(index) + "] | current length is [" + std::to_string(_length) + "]\n");
    }
}

template <typename T>
void Array<T>::replace(size_t index, T element)
{
    if (index <= _length - 1)
        arr[index] = element;
    else
        throw std::out_of_range("wrong index [" + std::to_string(index) + "]  | current length is [" + std::to_string(_length) + "]\n");
}

/* this version of reverse() is not efficient */
// template <typename T>
// void Array<T>::reverse()
// {
//     Array<T> *newArray = new Array<T>(_size);
//     size_t newArrayIndex = 0;
//     for (int i = _length - 1; i >= 0; i--)
//     {
//         newArray->add(arr[i]);
//     }
//     for (int i = 0; i < _length; i++)
//     {
//         arr[i] = newArray->get(i);
//     }
//     free(newArray);
// }

template <typename T>
void Array<T>::reverse()
{
    int i = 0, j = _length - 1;
    for (i; i < j;)
        std::swap(arr[i++], arr[j--]);
}

template <typename T>
Array<T> &Array<T>::merge(Array<T> &array)
{
    size_t newSize = array.length() + _length;
    _size = newSize;
    T *newArr = new T[newSize];
    for (size_t i = 0; i < _length; i++)
    {
        newArr[i] = arr[i];
    }
    for (size_t i = 0; i < array.length(); i++)
    {
        newArr[i + _length] = array.get(i);
    }
    _length = newSize;
    delete[] arr;
    arr = newArr;
    return *this;
}

template <typename T>
void Array<T>::leftShift()
{
    if (_length > 0)
        remove(0);
}

template <typename T>
void Array<T>::leftRotate()
{
    if (_length > 0)
    {
        T firstElement = arr[0];
        remove(0);
        add(firstElement);
    }
}

template <typename T>
void Array<T>::rightShift()
{
    if (_length > 0)
        rightRotate();
    remove(0);
}

template <typename T>
void Array<T>::rightRotate()
{
    if (_length > 0)
    {
        T lastElement = arr[_length - 1];
        for (int i = _length - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = lastElement;
    }
}

template <typename T>
bool Array<T>::operator==(Array<T> &array) const
{
    if (_length == array.length())
    {
        for (int i = 0; i < _length; i++)
        {
            if (arr[i] != array.get(i))
                return false;
        }
        return true;
    }
    return false;
}

template <typename T>
void Array<T>::operator=(Array<T> &array)
{
    _length = 0;
    _size = array.length();
    for (size_t i = 0; i < array.length(); i++)
    {
        add(array.get(i));
    }
}

template <typename T>
void Array<T>::operator+=(Array<T> &array)
{
    merge(array);
}

template <typename T>
T Array<T>::operator[](size_t index)
{
    return get(index);
}

template <typename T>
Array<T> Array<T>::operator+(Array<T> &array)
{
    size_t newSize = array.length() + _length;
    Array<T> newArray = Array<T>(newSize);
    for (size_t i = 0; i < _length; i++)
    {
        newArray.add(arr[i]);
    }
    for (size_t i = 0; i < array.length(); i++)
    {
        newArray.add(array.get(i));
    }
    return newArray;
}