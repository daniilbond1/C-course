#include <iostream>

/*
 * Delete spaces.
 *
 * @param in input
 * @param ok logic
 * @return input witout spaces 
 */
void delete_spaces() {

    char in;
    bool ok = true;
    while (std::cin.get(in))
        if (in != ' ') {
            std::cout << in;
            ok = true;
        }
        else if (ok) {
            std::cout << in;
            ok = false;
        }
}

int main() {

    delete_spaces();

    return 0;
}
