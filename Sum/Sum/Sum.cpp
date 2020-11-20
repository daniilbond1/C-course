#include <iostream>
using namespace std;
/*
 * Powering number.
 *
 * @param tests number of sums
 * @param a left term
 * @param b right term
 * @return (a+b)
 */

void sum() {
    int tests = 0;
    int a = 0;
    int b = 0;
    int answer = 0;
    cin >> tests;
    for (int g = 0;g < tests;g++)
    {
        cout << "insert a: ";
        cin >> a;
        cout << "insert b: ";
        cin >> b;
        answer = a + b;
        cout <<"answer: "<< answer << endl;
    }
}

int main()
{
    sum();
    return 0;
}