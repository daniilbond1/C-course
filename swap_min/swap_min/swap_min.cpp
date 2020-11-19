#include <iostream>

void swap_min(int* m[], unsigned rows, unsigned cols)
{
    int t = m[0][0];
    int z = 0;
    int k[cols];

    for (int i = 0;i != rows;i++) {
        for (int j = 0;j != cols;j++) {
            if (m[i][j] < t) {
                t = m[i][j];
                z = i;
            }
        }
    }

    for (int j = 0;j != cols;j++) {
        k[j] = m[z][j];
        m[z][j] = m[0][j];
        m[0][j] = k[j];
    }
}


int** create(size_t a, size_t b) {
    int** m = new int* [a];
    m[0] = new int[a * b];
    for (size_t i = 1; i != a; ++i) {
        m[i] = m[i - 1] + b;
    }
    return m;
}

int main()
{
    unsigned rows = 4;
    unsigned cols = 3;
    size_t a = 3;
    size_t b = 4;

    int** m = create(a, b);

    swap_min(m,rows, cols);

    return 0;
}


