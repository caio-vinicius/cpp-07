/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void toIter(T &e);

template <typename T>
void iter(T *a, const unsigned int length, void (*f)(T &));

#endif
