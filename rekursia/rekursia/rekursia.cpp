#include <iostream>
using namespace std;


void rec() {
    int input =0;
        cin >> input;
    if (input == 0) {
        return;
    }
    rec();
    cout << input << ' ';
}
        
int main() {

        rec();

        return 0;
    }