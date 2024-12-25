#include <iostream>
#include "array.h"
using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Array<int> arr1(10);
    Array<int> arr2(5, 10, 99);
    Array<int> arr3;
    cout << "array1: ";
    arr1.print(); 
    cout << "array2: ";
    arr2.print();

    arr2.append(3);
    arr2.print();
    arr2.errase(0);
    arr2.print();

    cout << arr1.get_capacity() << endl;
    cout << arr3.get_capacity() << endl;

    return 0;
}
