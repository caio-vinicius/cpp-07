/* Copyright (c) 2022 Caio Souza, Gustavo Ariadno. All rights reserved. */
/* 42 */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
 public:
    Array(void);
    ~Array(void);
    Array<T> &operator=(Array const &rhs);
    Array(Array const &src);

    Array(unsigned int n);
    Array(int n);
    T operator[](const int i) const;
    T &operator[](const int i);
    unsigned int size() const;

    struct IndexOutOfRange : public std::exception {
        const char *error() const;
    };
 private:
    T *data;
    unsigned int length;
};

#endif
