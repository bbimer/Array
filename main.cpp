#include <iostream>
#include "array.h"
using namespace std;

int main() {
    Array arr1(5, 10, 20);
    cout << "array1: ";
    arr1.print(); 
    Array arr2(5, 10, 30);
    cout << "array 2: ";
    arr2.print();
    cout << "=================" << endl;
    arr1.sorted();
    arr2.sorted();
    cout << "=================" << endl;
    cout << "min value - " << arr2.min() << endl;
    cout << "max value - " << arr2.max() << endl;
    cout << "=================" << endl;
    arr1 = arr2;
    arr1.print();
    cout << "=================" << endl;
    Array arr3 = arr1 + arr2;
    arr3.print();
    cout << "=================" << endl;
    //arr1 += arr2;
    //arr1.print();

    return 0;
}
