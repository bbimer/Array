#include <iostream>
#include "array.h"
using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Array<int> arr1(5, 10, 99);
    Array<int> arr2(5, 10, 99);
    cout << "array1: ";
    arr1.print(); 
    cout << "array2: ";
    arr2.print();

    cout << (arr1 + arr2) << endl;

    return 0;
}
