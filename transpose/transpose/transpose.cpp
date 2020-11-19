#include <iostream>

int** transpose(const int* const* m, unsigned rows, unsigned cols)
{
   int** z= create(cols,rows );
    for (int i = 0;i != rows;i++) {
        for (int j = 0;j != cols;j++) {
            z[j][i] = m[i][j];
        }
    }
    return z;
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
    size_t a = 2;
    size_t b = 3;
    const int* const* m;
    m = create(a, b);
    unsigned rows=2;
    unsigned cols=3;
    transpose(m,rows,cols);
}


