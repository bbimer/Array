#include <iostream>
#include "array.h"
using namespace std;

int main() {
    Array arr1(5); 
    arr1.print(); 

    Array arr2(5, 10, 30);
    arr2.print();

    arr2.sorted();
    cout << "min value - " << arr2.min() << endl;
    cout << "max value - " << arr2.max() << endl;

    return 0;
}
