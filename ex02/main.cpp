/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#include <iostream>
#include <cstdlib>

#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << "Test 0: No parameter, empty array" << std::endl;
    {
        Array<int> numbers;
        std::cout << "  " << "length: " << numbers.size() << std::endl;
    }
    std::cout << "Test 1: Create a array with N as parameter, using " << MAX_VAL << std::endl;
    Array<int> numbers(MAX_VAL);
    std::cout << "  " << "length: " << numbers.size() << std::endl;
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPES
    std::cout << "Test 2: Copy assignment and constructor, deep copy" << std::endl;
    {
        //assignment operator copy
        Array<int> tmp = numbers;
        //copy constructor copy
        Array<int> test(tmp);

        //test it
        std::cout << "  " << "length tmp: " << tmp[0] << std::endl;
        std::cout << "  " << "length test: " << test[0] << std::endl;
        std::cout << "  " << "changing tmp to 0" << std::endl;
        tmp[0] = 0;
        std::cout << "  " << "length tmp: " << tmp[0] << std::endl;
        std::cout << "  " << "length test: " << test[0] << std::endl;
    }
    std::cout << "Test 3: If the values are saved equal" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        if (numbers[0] != tmp[0]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
        std::cout << "  " << "OK" << std::endl;
    }
    std::cout << "Test 4: Overall size is equal" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        std::cout << "  " << "size1: " << numbers.size() << std::endl;
        std::cout << "  " << "size2: " << tmp.size() << std::endl;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "Test 5: Acessing wrong indexes" << std::endl;
    try {
        numbers[-2] = 0;
    }
    catch(const Array<int>::IndexOutOfRange &e) {
        std::cerr << "  " << e.error() << '\n';
    }
    try {
        numbers[MAX_VAL - 1] = 0;
    }
    catch(...) {
        std::cerr << "error" << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return (0);
}
