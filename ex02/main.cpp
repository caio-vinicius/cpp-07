#include <iostream>
#include <cstdlib>

#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPES
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        if (numbers[0] != tmp[0]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        std::cout << "size1: " << numbers.size() << std::endl;
        std::cout << "size2: " << tmp.size() << std::endl;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[-2] = 0;
    }
    catch(const Array<int>::IndexOutOfRange &e) {
        std::cerr << e.error() << '\n';
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
