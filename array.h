﻿#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    size_t size;
    T* array;

public:
    Array(size_t n) : size(n) {
        array = new T[size]();
    }

    Array(size_t n, T min, T max) : size(n) {
        array = new T[size];
        for (size_t i = 0; i < size; ++i)
        {
            array[i] = min + rand() % (max - min + 1);
        }
    }

    Array(const Array& other) : size(other.size), array(nullptr) {
        if (size > 0) {
            array = new T[size];
            for (size_t i = 0; i < size; ++i)
            {
                array[i] = other.array[i];
            }
        }
    }


    Array(Array&& move) noexcept : size(move.size), array(move.array) {
        move.array = nullptr;
        move.size = 0;
    }

    Array& operator=(const Array& other) {
        if (this == &other) return *this;
        delete[] array;

        size = other.size;
        array = new T[size];
        for (size_t i = 0; i < size; ++i)
        {
            array[i] = other.array[i];
        }
        return *this;
    }

    Array& operator=(Array&& right) noexcept {
        if (this == &right) return *this;

        delete[] array;
        size = right.size;
        array = right.array;

        right.size = 0;
        right.array = nullptr;

        return *this;
    }

    Array operator+(const Array& other) {
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

    Array& operator+=(const Array& other) {
        *this = *this + other;
        return *this;
    }

    T& operator[](size_t index) {
        return array[index];
    }

    friend ostream& operator<<(ostream& os, const Array& arr) {
        for (size_t i = 0; i < arr.size; ++i) {
            os << arr.array[i] << " ";
        }
        return os;
    }



    bool operator==(const Array& other) const {
        if (size != other.size) return false;
        for (size_t i = 0; i < size; ++i)
        {
            if (array[i] != other.array[i]) return false;
        }
        return true;
    }


    bool operator!=(const Array& other) const {
        return !(*this == other);
    }

    bool operator>(const Array& other) const {
        return (size > other.size);
    }

    bool operator<(const Array& other) const {
        return (size < other.size);
    }

    T min() const {
        if (size == 0)
        {
            cout << "Array is empty. Returning 0." << endl;
            return 0;
        }
        T min_value = array[0];
        for (size_t i = 1; i < size; ++i)
        {
            if (array[i] < min_value) {
                min_value = array[i];
            }
        }
        return T();
    }

    T max() const {
        if (size == 0)
        {
            cout << "Array is empty. Returning 0." << endl;
            return 0;
        }
        T max_value = array[0];
        for (size_t i = 1; i < size; ++i)
        {
            if (array[i] > max_value) {
                max_value = array[i];
            }
        }
        return T();
    }

    void sorted() const {
        for (size_t i = 0; i < size - 1; ++i)
        {
            for (size_t j = 0; j < size - i - 1; ++j)
            {
                if (array[j] > array[j + 1])
                {
                    T temp = array[j];
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

    ~Array() {
        delete[] array;
        array = nullptr;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

};
