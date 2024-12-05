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

    void print() const;
};
