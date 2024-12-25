#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    static const size_t cnt_capacity = 80;
    size_t capacity;
    size_t size;
    T* array;

    void rlz_capacity(size_t new_capacity) {
        T* new_array = new T[new_capacity];
        for (size_t i = 0; i < size; ++i)
        {
            new_array[i] = array[i];
        }

        delete[] array;
        array = new_array;
        capacity = new_capacity;
    }

public:
    Array() : size(0), capacity(cnt_capacity), array(new T[cnt_capacity]) {}
    
    Array(size_t init_capacity) : size(0), capacity(init_capacity), array(new T[init_capacity]) {}

    Array(size_t size, T min, T max) : size(size), capacity(size), array(new T[size]) {
        for (size_t i = 0; i < size; ++i)
        {
            array[i] = min + rand() % (max - min + 1);
        }
    }

    Array(const Array& other) : size(other.size), capacity(other.capacity), array(new T(other.capacity)) {
        for (size_t i = 0; i < size; ++i)
        {
            array[i] = other.array[i];
        }
    }

    Array(Array&& move) noexcept : size(move.size), capacity(move.capacity), array(move.array) {
        move.size = 0;
        move.capacity = 0;
        move.array = nullptr;
    }

    Array& operator=(const Array& other) {
        if (this == &other) return *this;
        delete[] array;

        size = other.size;
        capacity = other.capacity;
        array = new T[capacity];
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
        capacity = right.capacity;
        array = right.array;

        right.size = 0;
        right.capacity = 0;
        right.array = nullptr;

        return *this;
    }

    Array operator+(const Array& other) {
        Array result(size + other.size);
        result = size + other.size;
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

    void sorted() {
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

    void append(const T& val) {
        if (size >= capacity)
            rlz_capacity(capacity * 2);
        array[size++] = val;
    }

    void errase(const T& idx) {
        if (idx > size) return;
        for (size_t i = idx; i < size; ++i)
            array[i] = array[i + 1];
        --size;
    }

    int get_size() const {
        return size;
    }

    int get_capacity() const {
        return capacity;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

};
