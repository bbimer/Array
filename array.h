#pragma once

class Array {
private:
    size_t size;
    int* array;

public:
    Array(size_t n = 0);
    Array(size_t n, int min, int max); 
    Array(const Array& other);
    ~Array();

    Array& operator=(const Array& other);
    Array operator+(const Array& other) const;


    int min() const;
    int max() const;
    void sorted();

    void print() const;
};
