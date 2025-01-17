/********************
 * File : array.cpp
 * Namespace :
 * Created : Tue Jan 7 2025
 * Modified : Fri Jan 17 2025
 * Author : Khaled Fathi
 * Email : dev@khaledfathi.com
 *
 * Array Datastructure template
 * CAUTION : DON'T USE THIS CODE IN PRODUCTION
 * THIS CODE IS JUST FOR LEARNING AND PRACTICE DATASTRUCTURE AND ALGORITHM
 ********************/
#include <string>           //used for : to_string
#include "../inc/array.hpp"
#include "../inc/exceptions/dsa_exceptions.hpp"

using namespace dsa;

template <typename T, int Size>
Array<T, Size>::Array() : _size(Size)
{
    arr = new T[_size];
    if (arr == NULL)
        throw NotEnoughMemoryException("Not enough memory");
}
template <typename T, int Size>
Array<T, Size>::Array(std::initializer_list<T> list) : _size(Size)
{
    if (list.size() > Size)
        throw ArrayInitializerException("Array Initialized with more thatn array size");
    arr = new T[Size];
    if (arr == NULL)
        throw NotEnoughMemoryException("Not enough memory");
    for (auto i : list)
        add(i);
}
template <typename T, int Size>
Array<T, Size>::Array(Array<T, Size> &array) : _size(Size)
{
    _length = 0;
    delete[] arr;
    arr = new T[Size];
    if (arr == NULL)
        throw NotEnoughMemoryException("Not enough memory");
    for (int i = 0; i < array.length(); i++)
        add(array.get(i));
}

template <typename T, int Size>
Array<T, Size>::~Array()
{
    delete[] arr;
    arr = nullptr;
}

template <typename T, int Size>
size_t Array<T, Size>::length() const
{
    return _length;
}

template <typename T, int Size>
T &Array<T, Size>::get(int index) const
{
    if (index < _length)
        return arr[index];
    else
        throw std::out_of_range("wrong index [" + std::to_string(index) + "]  | current length is [" + std::to_string(_length) + "]\n");
}

template <typename T, int Size>
int Array<T, Size>::find(T element) const
{
    for (int i = 0; i < _length; i++)
        if (element == arr[i])
            return i;
    return -1;
}

template <typename T, int Size>
T Array<T, Size>::first() const
{
    return get(0);
}
template <typename T, int Size>
T Array<T, Size>::last() const
{
    return get(_length - 1);
}

template <typename T, int Size>
void Array<T, Size>::add(T element)
{
    if (_length < _size)
        arr[_length++] = element;
}

template <typename T, int Size>
void Array<T, Size>::insert(size_t index, T element)
{
    if (_length >= _size)
        throw std::out_of_range("no room for new value , Array is Full ");
    if (index > _length)
        throw std::out_of_range("wrong index [" + std::to_string(index) + "] | current length is [" + std::to_string(_length) + "]\n");
    if (_length < _size)
    {
        for (int i = _length - 1; i >= 0; i--)
            if (i != index)
                arr[i + 1] = arr[i];
            else
            {
                arr[i + 1] = arr[i];
                arr[i] = element;
                break;
            }
        _length++;
    }
}

template <typename T, int Size>
void Array<T, Size>::remove(size_t index)
{
    if (index < _length)
    {
        for (index; index < _length; index++)
            if (index + 1 < _length)
                arr[index] = arr[index + 1];
        _length--;
    }
    else
        throw std::out_of_range("wrong index [" + std::to_string(index) + "] | current length is [" + std::to_string(_length) + "]\n");
}

template <typename T, int Size>
void Array<T, Size>::replace(size_t index, T element)
{
    if (index <= _length - 1)
        arr[index] = element;
    else
        throw std::out_of_range("wrong index [" + std::to_string(index) + "]  | current length is [" + std::to_string(_length) + "]\n");
}

template <typename T, int Size>
void Array<T, Size>::reverse()
{
    int i = 0, j = _length - 1;
    for (i; i < j;)
        std::swap(arr[i++], arr[j--]);
}

template <typename T, int Size>
Array<T, Size> &Array<T, Size>::merge(Array<T, Size> &array)
{
    size_t newSize = array.length() + _length;
    _size = newSize;
    T *newArr = new T[newSize];
    for (size_t i = 0; i < _length; i++)
        newArr[i] = arr[i];
    for (size_t i = 0; i < array.length(); i++)
        newArr[i + _length] = array.get(i);
    _length = newSize;
    delete[] arr;
    arr = newArr;
    return *this;
}

template <typename T, int Size>
void Array<T, Size>::leftShift()
{
    if (_length > 0)
        remove(0);
}

template <typename T, int Size>
void Array<T, Size>::leftRotate()
{
    if (_length > 0)
    {
        T firstElement = arr[0];
        remove(0);
        add(firstElement);
    }
}

template <typename T, int Size>
void Array<T, Size>::clear()
{
    _length = 0;
}

template <typename T, int Size>
void Array<T, Size>::rightShift()
{
    if (_length > 0)
        rightRotate();
    remove(0);
}

template <typename T, int Size>
void Array<T, Size>::rightRotate()
{
    if (_length > 0)
    {
        T lastElement = arr[_length - 1];
        for (int i = _length - 1; i > 0; i--)
            arr[i] = arr[i - 1];
        arr[0] = lastElement;
    }
}

template <typename T, int Size>
bool Array<T, Size>::operator==(Array<T, Size> &array) const
{
    if (_length == array.length())
    {
        for (int i = 0; i < _length; i++)
            if (arr[i] != array.get(i))
                return false;
        return true;
    }
    return false;
}

template <typename T, int Size>
Array<T, Size> &Array<T, Size>::operator=(std::initializer_list<T> list)
{
    clear();
    if (list.size() > Size)
        throw ArrayInitializerException("Array Initialized with more thatn array size");
    arr = new T[Size];
    if (arr == NULL)
        throw NotEnoughMemoryException("Not enough memory");
    _size = Size;
    for (auto i : list)
        add(i);
    return *this;
}

template <typename T, int Size>
Array<T, Size> &Array<T, Size>::operator=(Array<T, Size> &array)
{
    _length = 0;
    delete[] arr;
    arr = new T[Size];
    if (arr == NULL)
        throw NotEnoughMemoryException("Not enough memory");
    _size = Size;
    for (int i = 0; i < array.length(); i++)
        add(array.get(i));
    return *this;
}
template <typename T, int Size>
T &Array<T, Size>::operator[](size_t index)
{
    return get(index);
}

template <typename T, int Size>
Array<T, Size> Array<T, Size>::operator+(Array<T, Size> &array)
{
    size_t newSize = array.length() + _length;
    Array<T, Size> newArray = Array<T, Size>(newSize);
    for (size_t i = 0; i < _length; i++)
        newArray.add(arr[i]);
    for (size_t i = 0; i < array.length(); i++)
        newArray.add(array.get(i));
    return newArray;
}