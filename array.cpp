#include <iostream>
#include "array.h"
using namespace std;

Array::Array(size_t n) : size(n) {  
    array = new int[size]();
}

Array::Array(size_t n, int min, int max) : size(n) {
    array = new int[size];
    srand(static_cast<unsigned>(time(nullptr)));
    for (size_t i = 0; i < size; ++i)
    {
        array[i] = min + rand() % (max - min + 1);
    } 
}

Array::Array(const Array& other) : size(other.size) {
    array = new int[size];
    for (size_t i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }
}

int Array::min() const {
    if (size != 0)
    {
        int min_value = array[0];
        for (size_t i = 1; i < size; ++i)
        {
            if (array[i] < min_value)
            {
                min_value = array[i];
            }
        }
        return min_value;
    }
}


int Array::max() const {
    if (size != 0)
    {
        int max_value = array[0];
        for (size_t i = 1; i < size; ++i)
        {
            if (array[i] > max_value)
            {
                max_value = array[i];
            }
        }
        return max_value;
    }
}

void Array::sorted() {
    for (size_t i = 0; i < size - 1; ++i)
    {
        for (size_t j = 0; j < size - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    cout << "sorted: ";
    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}



Array::~Array() {
    delete[] array;
    array = nullptr;
}

void Array::print() const {
    for (size_t i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
