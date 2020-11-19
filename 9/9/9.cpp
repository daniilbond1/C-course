#include <iostream>
#include <string>
using namespace std;

int polindrome(string a) {

    int size = 0;
    int ostatok = 0;
    int seredina = 0;
    int sovpalo = 0;

    size = a.length();

    ostatok = size % 2;


    if (size == 1) {
        return 0;
    }

    if (ostatok == 1) {
        seredina = (size - 1) / 2;
        for (int i = 0;i != seredina;i++) {
            if (a[seredina - 1 - i] == a[seredina + 1 + i]) {
                sovpalo++;
            }
        }
        if (seredina == sovpalo) {
            return 0;
        }
        return  (seredina - sovpalo) - 1;
    }

    if (ostatok == 0) {
        seredina = size / 2;
        for (int i = 0;i != seredina;i++) {
            if (a[seredina - 1 - i] == a[seredina + i]) {
                sovpalo++;
            }
        }
        if (seredina == sovpalo) {
            return 0;
        }
        return  (seredina - sovpalo) - 1;
    }

}






int main()
{

    string a;

    cin >> a;

    cout << polindrome(a);


    return 0;
}