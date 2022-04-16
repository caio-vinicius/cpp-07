/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#include <exception>
#include <iostream>

#include "Array.hpp"

template <typename T>
const char *Array<T>::IndexOutOfRange::error() const {
    return "Index out of range.";
}

template <typename T>
Array<T>::Array(): length(0) {
    Array::data = new int();
}

template <typename T>
Array<T>::~Array() {
    delete[] Array::data;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs) {
    if (this == &rhs)
        return (*this);
    Array::data = new T[rhs.length];
    std::copy(rhs.data, rhs.data + rhs.length, Array::data);
    Array::length = rhs.length;
    return (*this);
}

template <typename T>
Array<T>::Array(Array const &src) {
    *this = src;
}

template <typename T>
Array<T>::Array(unsigned int n): length(n) {
    Array::data = new T[n];
}

template <typename T>
Array<T>::Array(int n): length(n) {
    Array::data = new T[n];
}

template <typename T>
T Array<T>::operator[](const int i) const {
    if (i >= 0 && i <= static_cast<int>(Array::length))
        return Array::data[i];
    else
        throw Array::IndexOutOfRange();
}

template <typename T>
T &Array<T>::operator[](const int i) {
    if (i >= 0 && i <= static_cast<int>(Array::length))
        return Array::data[i];
    else
        throw Array::IndexOutOfRange();
}

template <typename T>
unsigned int Array<T>::size(void) const {
    return (Array::length);
}

template class Array<int>;
