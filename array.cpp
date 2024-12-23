#include <iostream>
#include "array.h"
using namespace std;

Array::Array(size_t n) : size(n) {  
    array = new int[size]();
}

Array::Array(size_t n, int min, int max) : size(n) {
    array = new int[size];
    for (size_t i = 0; i < size; ++i)
    {
        array[i] = min + rand() % (max - min + 1);
    }
}

Array::Array(const Array& other) : size(other.size), array(nullptr) {
    if (size > 0) {
        array = new int[size];
        for (size_t i = 0; i < size; ++i)
        {
            array[i] = other.array[i];
        }
    }
}


Array::Array(Array&& move) noexcept : size(move.size), array(move.array) {
    move.array = nullptr;
    move.size = 0;
}

Array& Array::operator=(const Array& other) {
    if (this == &other) return *this;
    delete[] array;

    size = other.size;
    array = new int[size];
    for (size_t i = 0; i < size; ++i)
        {
            array[i] = other.array[i];
        }
    return *this;
}

Array& Array::operator=(Array&& right) noexcept {
    if (this == &right) return *this;

    delete[] array;
    size = right.size;
    array = right.array;

    right.size = 0;
    right.array = nullptr;

    return *this;
}

Array Array::operator+(const Array& other) const {
    Array result(size + other.size);
    for (size_t i = 0; i < size; ++i)
    {
        result.array[i] = array[i];
    }
    for (size_t i = 0; i < other.size; ++i)
    {
        result.array[size + i] = other.array[i];
    }
    return result;
}

Array& Array::operator+=(const Array& other) {
    *this = *this + other;
    return *this;
}

int& Array::operator[](size_t index) {
    return array[index];
}

ostream& operator<<(ostream& os, const Array& arr) {
    for (size_t i = 0; i < arr.size; ++i)
    {
        os << arr.array[i] << " ";
    }
    return os;
}

bool Array::operator==(const Array& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; ++i)
    {
        if (array != other.array) return false;
    }
    return true;
}

bool Array::operator!=(const Array& other) const {
    return !(*this == other);
}

bool Array::operator>(const Array& other) const {
    return (size > other.size);
}

bool Array::operator<(const Array& other) const {
    return (size < other.size);
}

int Array::min() const {
    if (size == 0)
    {
        cout << "Array is empty. Returning 0." << endl;
        return 0;
    }
    int min_value = array[0];
    for (size_t i = 1; i < size; ++i)
    {
        if (array[i] < min_value) {
            min_value = array[i];
        }
    }
    return min_value;
}

int Array::max() const {
    if (size == 0)
    {
        cout << "Array is empty. Returning 0." << endl;
        return 0;
    }
    int max_value = array[0];
    for (size_t i = 1; i < size; ++i)
    {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }
    return max_value;
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
