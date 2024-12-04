#include <iostream>
#include "array.h"
using namespace std;


Array::Array(size_t n) : size(n), array(nullptr) {
	if (size > 0)
	{
		array = new int[size] {};
		srand(time(nullptr));
		for (size_t i = 0; i < size; ++i)
		{
			array[i] = rand() % 100;
		}
	}
}

Array::~Array() {
	delete[] array;
}

void Array::print() const {
	for (size_t i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}
}

//Array::Array(const Array &other) {
//
//}


