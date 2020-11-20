#include <iostream>
#include <cmath>
using namespace std;

/*
 * Quadratic solution
 *
 * @param a first quadratic equation
 * @param b second quadratic equation
 * @param c third quadratic equation
 * @param D discriminant
 * @param x1 answer 
 * @param x2 answer
 * @return x,y
 */

void quadratic_solution() {
    int a, b, c, D;
    double x1,x2;


    cin >> a >> b >> c;

    D = b * b - 4 * a * c;

    if (D >= 0) {
        x1 = (-b - sqrt(D)) / (2 * a);
        x2 = (-b + sqrt(D)) / (2 * a);
        cout << x1 << endl;
        cout << x2 << endl;
    }
    if (D < 0) {
        cout << "No real roots\n";
    }
}


int main()
{
    quadratic_solution();
    return 0;
}