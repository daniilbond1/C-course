#include <iostream>
using namespace std;


void  rotate(int a[], unsigned size, int shift)
{
    shift = shift % size;
    int* element1 = &a[0];
    int* element2 = &a[1];
    int konteiner = 0;

    for (int i = 0; i < shift; ++i) {

        for (int i = 0; i < (size - 1); ++i) {

            konteiner = a[i];
            *element1 = a[i + 1];
            *element2 = konteiner;
            element1 = element1 + 1;
            element2 = element2 + 1;
        }
        element1 = element1 + 1 - size;
        element2 = element2 + 1 - size;
    }
    return;
}


int main() { 
    unsigned size = 8;
    int shift = 0;
    int a[9] = { 1,2,3,4,5,6,7,8,9};

    rotate(a, size, shift);

    return 0;
}