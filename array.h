#pragma once

class Array
{
private:
	size_t size;
	int* array;

public:
	Array(size_t n = 0);
	~Array();

	void print() const;
};