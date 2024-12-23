#include <iostream>
#include "array.h"
using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Array arr1(5, 10, 99);
    cout << "array1: ";
    arr1.print(); 
    Array arr2(5, 10, 99);
    cout << "array 2: ";
    arr2.print();
    cout << "=================" << endl;
    cout << "sorted: " << endl;
    cout << "arr1 - ";
    arr1.sorted();
    cout << "arr2 - ";
    arr2.sorted();
    cout << "=================" << endl;
    cout << "min value - " << arr2.min() << endl;
    cout << "max value - " << arr2.max() << endl;
    cout << "=================" << endl;
    cout << "operator = " << endl;
    //arr1 = arr2;
    //arr1.print();
    cout << "=================" << endl;
    cout << "operator + " << endl;
    Array arr3 = arr1 + arr2;
    arr3.print();
    cout << "=================" << endl;
    cout << "operator += " << endl;
    arr1 += arr2;
    arr1.print();
    cout << "=================" << endl;
    cout << "operator [] " << endl;
    cout << arr2[0] << endl;
    cout << "=================" << endl;
    cout << "operator << " << endl;
    cout << arr1 << endl;
    cout << "=================" << endl;
    cout << "operator == " << endl;
    cout << (arr1 == arr2) << endl;
    cout << "=================" << endl;
    cout << "operator != " << endl;
    cout << (arr1 != arr2) << endl;
    cout << "=================" << endl;
    cout << "operator > " << endl;
    cout << (arr1 > arr2) << endl;
    cout << "=================" << endl;
    cout << "operator < " << endl;
    cout << (arr1 < arr2) << endl;
    cout << "=================" << endl;
    Array arr4(6, 10, 99);
    Array arr5 = std::move(arr4);
    cout << "operator (move)" << endl;
    cout << arr5 << endl;

    return 0;
}
