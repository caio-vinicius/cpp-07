/* Copyright (c) 2022 Caio Souza, Gustavo Ariadno. All rights reserved. */
/* 42 */

#include "iter.hpp"

template <typename T>
void toIter(T &e) {
    e += 1;
}

template <typename T>
void iter(T *a, const unsigned int length, void (*f)(T &)) {
    for (unsigned int i = 0; i < length; i++) {
        f(a[i]);
    }
}

int main(void) {
    {
        const unsigned int l = 3;
        char a[l] = {1,1,1};

        iter(a, l, &toIter);
    }
    {
        const unsigned int l = 3;
        char a[l] = {1,1,1};

        iter(a, l, &toIter<char>);
    }
    //{
    //    const unsigned int l = 3;
    //    char a[l] = {1,1,1};

    //    iter(a, l, &toIter<int>);
    //}
    {
        const unsigned int l = 3;
        int a[l] = {1,1,1};

        iter(a, l, &toIter<int>);
    }
    {
        const unsigned int l = 3;
        double a[l] = {1.1,1.1,1.1};

        iter(a, l, &toIter<double>);
    }
    return (0);
}
