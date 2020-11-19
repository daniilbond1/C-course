#include <iostream>
using namespace std;

/*
 * Powering number.
 *
 * @param x number to power
 * @param p power
 * @return x^p
 */
int powered(int x, unsigned p) {

    int answer = 1;

    if (p >= 1) {
        for (int t = 0; t < p; t++) {
            answer = answer * x;
        }
    }
    if (p == 0){
        for (int t = 0; t < p; t++) {
            answer = 1;
        }
    }

    return answer;
}

int main()
{
    int number = 0;
    unsigned power = 0;
    cout << "Insert number: ";
    cin >> number;
    cout << "Insert power: ";
    cin >> power;
   cout<< "Answer: "<<powered(number, power);
    return 0;
}