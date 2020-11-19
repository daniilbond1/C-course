
#include <iostream>
using namespace std;


void  rotate(int a[], unsigned size, int shift)
{
    shift = shift % size;
    int* p = &a[0];
    int* z = &a[1];
    int k = 0;

    for (int i = 0; i < shift; ++i) {

        for (int i = 0; i < (size - 1); ++i) {

            k = a[i];
            *p = a[i + 1];
            *z = k;
            p = p + 1;
            z = z + 1;
        }
        p = p + 1 - size;
        z = z + 1 - size;
    }

    for (int i = 0; i < size; ++i) {
        cout << a[i] << ' ';
        cout << endl;
    }

    return;
}



int main()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int size = 5;
    int shift = 2;

    rotate(a, size, shift);

    return 0;
}

