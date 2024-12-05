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
