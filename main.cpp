#include <iostream>
#include "array.h"
using namespace std;

int main() {
    Array arr1(5); 
    arr1.print(); 

    Array arr2(5, 10, 30);
    arr2.print();

    return 0;
}
