﻿#pragma once

class Array {
private:
    size_t size;
    int* array;

public:
    Array(size_t n = 0);
    Array(size_t n, int min, int max); 
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array();

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
    Array operator+(const Array& other) const;
    Array& operator+=(const Array& other);
    int& operator[](size_t index);
    bool operator==(const Array& other) const;
    bool operator!=(const Array& other) const;
    bool operator>(const Array& other) const;
    bool operator<(const Array& other) const;


    int min() const;
    int max() const;
    void sorted();

    void print() const;
    friend std::ostream& operator<<(std::ostream& os, const Array& arr);
};
