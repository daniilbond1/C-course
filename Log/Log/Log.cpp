#include <iostream>
using namespace std;
/*
 * calculating base 2 integer logarithm
 *
 * @param input number to log
 * @param tests number of tests
 * @return log base 2 from input
 */

void log() 
    {
        int tests = 0;
        int input = 0;

        cin >> input;

        for (int g = 0;g < input; g++)
        {
            int p = 0;
            int b = 1;
            cin >> input;
            while (b <= input) {
                b = b * 2;
                p = p + 1;
            }
            cout << p - 1 << endl;
        }
    }


int main(){

    log();

    return 0;
}